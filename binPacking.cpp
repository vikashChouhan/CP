#include<bits/stdc++.h>
using namespace std;

/*
//next fit
int main()
{
    int size;
    cin>>size;
    int c;
    cin>>c;
    int cnt=0,remSize=c;
    for(int i=0;i<size;i++){
    	int v;
    	cin>>v;
    	
    	if(remSize<v){
    		cnt++;
    		remSize=c-v;
		}
		else
			remSize-=v;
	}
	cout<<cnt<<"\n";

}*/

/*
//first fit
int main()
{
	int size;
    cin>>size;
    int c;
    cin>>c;
    int cnt=0;
    int remSize[100]={0},rems=0;
    for(int i=0;i<size;i++){
    	int v;
    	cin>>v;
    	int j=0;
    	for(j=0;j<rems;j++)
    		if(remSize[j]>v)
    			break;
    	
    	if(j==rems){
    		remSize[rems++]=c-v;
    		cnt++;
		}
		else{
			remSize[j]-=v;
		}
	}
	cout<<cnt;
}
*/

//best fit
int main()
{
	int size;
    cin>>size;
    int c;
    cin>>c;
    int cnt=0;
    int remSize[100]={0},rems=0;
    for(int i=0;i<size;i++){
    	int v;
    	cin>>v;
    	
    	int min=c+1,idx=0;
    	for(int j=0;j<rems;j++){
    		if(remSize[j]>=v && remSize[j]-v<min){
    			min = remSize[j]-v;
    			idx=j;
			}
		}
		
		if(min==c+1){
			cnt++;
			remSize[rems++]=c-v;
		}
		else{
			remSize[idx]-=v;
		}
	}
	cout<<cnt;
}
