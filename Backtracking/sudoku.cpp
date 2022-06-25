/*
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
*/

#include<bits/stdc++.h>
using namespace std;

int arr[9][9];

bool safe(int i,int j,int k){
    for(int m=0;m<9;m++){
        if(arr[i][m]==k){
            return false;
        }
        if(arr[m][j]==k){
            return false;
        }
    }
    int starti=i-i%3;
    int startj=j-j%3;
    for(int m=0;m<3;m++){
        for(int n=0;n<3;n++){
            if(arr[starti+m][startj+n]==k){
                return false;
            }
        }
    }
    return true;
}

bool solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(safe(i,j,k)){
                        arr[i][j]=k;
                        bool t=solve();
                        if(t){
                            return true;
                        }
                        else{
                            arr[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    
    // write your code here
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }
    bool t=solve();
    if(t){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}