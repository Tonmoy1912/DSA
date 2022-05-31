/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.*/

/*logic:
XOR of two same integer is 0. (5^5=0).
Also, XOR operation is commutative.
So, XOR of all element in the array is equal to the unique element*/

int findUnique(int *arr, int n) {
    // Write your code here
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;    
}