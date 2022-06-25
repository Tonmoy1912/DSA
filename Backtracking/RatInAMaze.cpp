/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix
*/

#include<bits/stdc++.h>
#include <stack>
#include<vector>
using namespace std;
int arr[18][18]={0};
int ans[18][18]={0};

void print(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
    }
    cout<<endl;
}

void ratInMaze(int i,int j,int n){
    if(i==(n-1)&&j==(n-1)){
        ans[i][j]=1;
        print(n);
        ans[i][j]=0;
        return ;
    }
    if(i<0||i>=n||j<0||j>=n||ans[i][j]==1||arr[i][j]==0){
        return ;
    }
    ans[i][j]=1;
    ratInMaze(i-1,j,n);
    ratInMaze(i+1,j,n);
    ratInMaze(i,j-1,n);
    ratInMaze(i,j+1,n);
    ans[i][j]=0;
    
}

int main() {

	// Write your code here
    vector<pair<int,int>> s;
    int n;
    cin>>n;
    //ans[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
	ratInMaze(0,0,n);
	return 0;
}
