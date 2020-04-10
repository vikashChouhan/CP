
MOD = 998244353

def power(a, n):
    if(n==0):
        return 1
    if(n&1):
        return (a* power(a*a, (n-1)//2))%MOD
    return power(a*a, n//2)%MOD

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    
    return x % m

def combine(l, r, op):

    res = list()
    if(op=='|'):
        res.append(((l[0]*r[0]) + (l[1]*r[0])))
        res.append((l[0]*r[1] + l[1]*r[1] + l[1]*r[2] + l[2]*r[1] + l[1]*r[3] + l[2]*r[3] + l[3]*(r[1] + r[2])))
        res.append((l[0]*r[2] + l[2]*r[0] + l[2]*r[2]))
        res.append((l[0]*r[3] + l[3]*r[3] + l[3]*r[0]))
                              
    elif(op=='&'):
        res.append((l[0]*(r[0]+r[1]+r[2]+r[3]) + l[1]*r[0] + l[2]*(r[0]+r[3]) + l[3]*(r[0]+r[2])))
        res.append((l[1]*r[2]))
        res.append((l[1]*r[2] + l[2]*(r[1]+r[2])))
        res.append((l[1]*r[3] + l[3]*r[3] + l[3]*r[1]))
        
    elif(op=='^'):
        res.append((l[0]*r[0] + l[1]*r[1] + l[2]*r[2] + l[3]*r[3]))
        res.append((l[0]*r[1] + l[1]*r[0] + l[2]*r[3] + l[3]*r[2]))
        res.append((l[0]*r[2] + l[2]*r[0] + l[1]*r[3] + l[3]*r[1]))
        res.append((l[1]*r[2] + l[2]*r[1] + l[0]*l[3] + l[3]*r[0]))

    return res
    
def solve(exp):

    stk = list()
    for ch in exp:
        
        if(ch!=')'):
            stk.append(ch)
        else:
            r = stk[-1]
            stk.pop()
            op = stk[-1]
            stk.pop()
            l = stk[-1]
            stk.pop()
            stk.pop()
            res = list()
            if(r=='#' and l=='#'):
                if(op=='|'):
                    res = [2,8,3,3]
                elif(op=='&'):
                    res = [9,1,3,3]
                elif(op == '^'):
                    res = [4,4,4,4]
            elif(r=='#'):
                res = combine(l,[1,1,1,1],op)
            elif(l=='#'):
                res = combine([1,1,1,1],r,op)
            else:
                res = combine(l,r,op)

            stk.append(res)

    return stk[-1]


while(1):
    a,b = list(map(int,input().split()))
    print((a*modinv(b,MOD))%MOD)
    
t = int(input())  
while(t>0):

    exp = input()

    v = list()
    if(len(exp)==1):
        v = [1,1,1,1]
    else:
        v = solve(exp)

    cnt = 0
    for ch in exp:
        if(ch=='#'):
           cnt+=1
    
    den = power(4,cnt)
    
    mi = modinv(den,MOD)

    print((v[0]*mi)%MOD, (v[1]*mi)%MOD, (v[2]*mi)%MOD, (v[3]*mi)%MOD)

    t-=1
