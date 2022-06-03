/*You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.*/

void sort012(int *arr, int n)
{	
    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zero++;
            arr[i]=2;
        }
        else if(arr[i]==1){
            one++;
            arr[i]=2;
        }
    }
    
    int i=0;
    while(zero>=1){
        arr[i++]=0;
        zero--;
    }
    while(one>=1){
        arr[i++]=1;
        one--;
    }
    
}