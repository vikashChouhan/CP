#include<bits/stdc++.h>
using namespace std;

#define li long int

struct node {
	li maxsum, prefixsum, suffixsum, sum;
};

/*void buildTree(node *tree,li *a,li i,li start,li end)
{
	if(start==end)
	{
		tree[i].sum=a[start];
		tree[i].prefixsum=a[start];
		tree[i].suffixsum=a[start];
		tree[i].maxsum = a[start];
	}
	else
	{
		li mid=(start+end)/2;
	
	buildTree(tree,a,2*i+1,0,mid);
	buildTree(tree,a,2*i+2,mid+1,end);
	
	tree[i].sum = tree[2*i+1].sum + tree[2*i+2].sum;
	
	tree[i].prefixsum = max(tree[2*i+1].prefixsum,tree[2*i+1].sum+tree[2*i+2].prefixsum);
	
	tree[i].suffixsum = max(tree[2*i+2].suffixsum,tree[2*i+2].sum+tree[2*i+1].suffixsum);
	
	li temp = max(tree[i].prefixsum,max(tree[i].suffixsum,max(tree[2*i+1].maxsum,max(tree[2*i+2].maxsum,tree[2*i+1].suffixsum+tree[2*i+2].prefixsum))));
	
	tree[i].maxsum = temp;
	}
}*/
void build(node *tree,li *arr, li low, li high, li index) 
{ 
    // the leaf node 
    if (low == high) { 
        tree[index].sum = arr[low]; 
        tree[index].prefixsum = arr[low]; 
        tree[index].suffixsum = arr[low]; 
        tree[index].maxsum = arr[low]; 
    } 
    else { 
        li mid = (low + high) / 2; 
          
        // left subtree 
        build(tree,arr, low, mid, 2 * index + 1); 
          
        // right subtree 
        build(tree,arr, mid + 1, high, 2 * index + 2); 
  
        // parent node's sum is the summation  
        // of left and rigth child 
        tree[index].sum = tree[2 * index + 1].sum +  
                          tree[2 * index + 2].sum; 
  
        // parent node's prefix sum will be equivalent 
        // to maximum of left child's prefix sum or left  
        // child sum + right child prefix sum. 
        tree[index].prefixsum =  
                    max(tree[2 * index + 1].prefixsum, 
                    tree[2 * index + 1].sum +  
                    tree[2 * index + 2].prefixsum); 
  
        // parent node's suffix sum will be equal to right 
        // child suffix sum or rigth child sum + suffix  
        // sum of left child 
        tree[index].suffixsum =  
                    max(tree[2 * index + 2].suffixsum, 
                    tree[2 * index + 2].sum +  
                    tree[2 * index + 1].suffixsum); 
  
        // maxum will be the maximum of prefix, suffix of 
        // parent or maximum of left child or right child 
        // and summation of left child's suffix and right  
        // child's prefix. 
        tree[index].maxsum =  
                    max(tree[index].prefixsum, 
                    max(tree[index].suffixsum, 
                    max(tree[2 * index + 1].maxsum, 
                    max(tree[2 * index + 2].maxsum, 
                    tree[2 * index + 1].suffixsum +  
                    tree[2 * index + 2].prefixsum)))); 
    } 
} 
/*node Query(node *tree,li i,li start,li end,li L,li R)
{
	
	if(start<=L && end>=R)
		return tree[i];
	
	li mid = (start+end)/2;
	
	if(L<=mid && R<=mid)
		return Query(tree,2*i+1,0,mid,L,R);
	else if(L>=mid+1 && R>=mid+1)
		return Query(tree,2*i+2,mid+1,end,L,R);
	
	else
	{
		node newnode;
		node left = Query(tree,2*i+1,0,mid,L,R);
		node right = Query(tree,2*i+2,mid+1,end,L,R);
		
		newnode.sum = left.sum + right.sum;
		
		newnode.prefixsum = max(left.prefixsum,left.sum+right.suffixsum);
		
		newnode.suffixsum = max(right.suffixsum,right.sum+left.suffixsum);
		
		li temp[] = {tree[i].prefixsum,tree[i].suffixsum,left.maxsum,right.maxsum,left.prefixsum+right.suffixsum};
		newnode.maxsum = *max_element(temp,temp+5);
		
		return newnode;
	
	}
}*/
node query(node *tree,li arr[], li index, li low,li high, li l, li r) 
{ 
    // initially all the values are INT_MIN 
    node result; 
    result.sum = result.prefixsum =  
                 result.suffixsum =  
                 result.maxsum = INT_MIN; 
  
    // range does not lies in this subtree 
    if (r < low || high < l) 
        return result; 
  
    // complete overlap of range 
    if (l <= low && high <= r) 
        return tree[index]; 
  
    li mid = (low + high) / 2; 
  
    // right subtree 
    if (l > mid) 
        return query(tree,arr, 2 * index + 2,  
                     mid + 1, high, l, r); 
          
    // left subtree     
    if (r <= mid) 
        return query(tree,arr, 2 * index + 1,  
                     low, mid, l, r); 
  
    node left = query(tree,arr, 2 * index + 1,  
                      low, mid, l, r); 
    node right = query(tree,arr, 2 * index + 2,  
                        mid + 1, high, l, r); 
  
    // finding the maximum and returning it 
    result.sum = left.sum + right.sum; 
    result.prefixsum = max(left.prefixsum, left.sum +  
                           right.prefixsum); 
                             
    result.suffixsum = max(right.suffixsum, 
                       right.sum + left.suffixsum); 
    result.maxsum = max(result.prefixsum, 
                    max(result.suffixsum, 
                    max(left.maxsum, 
                    max(right.maxsum, 
                    left.suffixsum + right.prefixsum)))); 
                      
    return result; 
} 
int main()
{
	li n;
	cin>>n;
	li a[n];
	for(li i=0;i<n;i++)
		cin>>a[i];
	
	node tree[4*n];
	build(tree,a,0,n-1,0);
		
	li m;
	cin>>m;
	while(m--)
	{
		li l,r;
		cin>>l>>r;
		cout<<query(tree,a,0,0,n-1,l-1,r-1).maxsum<<"\n";
	}
}
