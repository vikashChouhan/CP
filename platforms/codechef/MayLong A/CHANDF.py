import math

t = int(input())

while(t>0):

    x,y, l,r = list(map(int,input().split()))
    if(x==0 or y==0 or r==0):
        print(l)
        continue

    curr = x|y
    while(curr<l or curr>r):
        if(curr > r):
            if(curr&(~r)>=l and curr&(~r)<=r):
                curr = curr&(~r)
                break
            elif(curr&(~r) < r):
                curr = curr&(~r)
            else:
                pos = int(math.log(curr-r,2))+1
                temp = curr>>pos
                temp = 1<<int(math.log((temp&(-temp)),2)+pos)
                curr = curr&(~temp)
        elif(curr<l):
            curr = curr|l

    print(curr)
                


    t-=1
