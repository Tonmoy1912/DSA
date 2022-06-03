/*You have been given a random integer array/list(ARR) of size N.
 You have been required to push all the zeros that are present in the array/list to the end of it.
 Also, make sure to maintain the relative order of the non-zero elements.*/

void pushZeroesEnd(int *input, int size)
{
    int count=0,j=0;
    for(int i=0;i<size;i++){
        if(input[i]!=0){
            input[j]=input[i];
            j++;
        }
        else{
            count++;
        }
    }
    for(int i=1;i<=count;i++){
        input[j]=0;
        j++;
    }
    
}