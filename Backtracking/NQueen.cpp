/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
*/

#include<iostream>
using namespace std;

void print(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

bool isSafe(int **arr,int i,int j,int n){
    for(int a=i-1,b=j+1;a>=0&&b<n;a--,b++){
        if(arr[a][b]==1){
            return false;
        }
    }
    for(int a=i-1,b=j-1;a>=0&&b>=0;a--,b--){
        if(arr[a][b]==1){
            return false;
        }
    }
    for(int k=i-1;k>=0;k--){
        if(arr[k][j]==1){
            return false;
        }
    }
    return true;
}

void place(int **arr,int i,int n){
    if(i==n){
        print(arr,n);
    }
    for(int j=0;j<n;j++){
        if(isSafe(arr,i,j,n)){
            arr[i][j]=1;
            place(arr,i+1,n);
            arr[i][j]=0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;;
        }
    }
    place(arr,0,n);
    return 0;
}