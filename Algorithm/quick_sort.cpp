#include<bits/stdc++.h>
using namespace std;

int partition(int input[],int start,int end){
    int x=input[start],count=0;
    for(int i=start+1;i<=end;i++){
        if(input[i]<x){
            count++;
        }
    }
    int c=start+count;
    swap(input[start],input[c]);
    int i=start,j=end;
    while(i<c&&j>c){
        if(input[i]<x){
            i++;
        }
        else if(input[j]>=x){
            j--;
        }
        else{
            swap(input[i++],input[j--]);
        }
    }
    return c;
}


void quickSort2(int input[],int start,int end){
    if(start>=end){
        return ;
    }
    int c=partition(input,start,end);
    quickSort2(input,start,c-1);
    quickSort2(input,c+1,end);
}