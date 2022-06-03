/*You have been given a random integer array/list(ARR) and a number X.
 Find and return the triplet(s) in the array/list which sum to X.
*/

#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int start,int end){
    int count=0,pivot=arr[start];
    for(int i=start;i<=end;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotindex=start+count;
    swap(arr[start],arr[pivotindex]);
    int i=start,j=end;
    while(i<pivotindex&&j>pivotindex){
        if(arr[i]<pivot){
            i++;
        }
        else if(arr[j]>=pivot){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
        }
    }
}


void quicksort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    int c=partition(arr,start,end);
    quicksort(arr,start,c-1);
    quicksort(arr,c+1,end);
}


int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    quicksort(arr,0,n-1);
    int count=0;
    for(int k=1;k<n-1;k++){
        int i=0,j=n-1;
    while(i<k&&k<j){
        if(arr[i]+arr[j]+arr[k]>num){
            j--;
        }
        else if(arr[i]+arr[j]+arr[k]<num){
            i++;
        }
        else{
            int i2=i+1,j2=j-1;
            if(arr[i]==arr[j]){
                count=count+(j-i)*(j-i-1)/2;
                return count;
            }
            else if(arr[i2]==arr[i]||arr[j2]==arr[j]){
                int t=0;
                while(1){
                    if(arr[i2]==arr[i]){
                        i2++;
                    }
                    else if(arr[j2]==arr[j]){
                        j2--;
                    }
                    else{
                        t=1;
                        break;
                    }
                    
                }
                if(i2>k){
                    i2=k;
                }
                if(j2<k){
                    j2=k;
                }
                count+=(i2-i)*(j-j2);
                i=i2;
                j=j2;
                
            }
            else{
                count++;
                i++;
                j--;
            }
        }
    }
    }
    return count;
}