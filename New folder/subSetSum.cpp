/*
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
*/

#include<bits/stdc++.h>
using namespace std;

//int count;

void solve(int *arr,int i,int sum,int k,int n,int &count){
    if(i==n){
        if(sum==k){
            count++;
        }
        return ;
    }
    solve(arr,i+1,sum,k,n,count);
    solve(arr,i+1,sum+arr[i],k,n,count);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t){
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        solve(arr,0,0,k,n,count);
        cout<<count<<endl;
        delete []arr;
		t--;
    }
    return 0;
}