void merge(int input[],int start,int end,int mid){
    int len=end-start+1;
    int *p=new int[len];
    int i=start,j=mid+1,k=0;
    while(i<=mid&&j<=end){
        if(input[i]<input[j]){
            p[k++]=input[i++];
        }
        else{
            p[k++]=input[j++];
        }
    }
    while(i<=mid){
        p[k++]=input[i++];
    }
    while(j<=end){
        p[k++]=input[j++];
    }
    for(int i=start,k=0;i<=end;i++,k++){
        input[i]=p[k];
    }
    delete []p;
    
}


void mergesort(int input[],int start,int end){
    if(start>=end){
        return ;
    }
    int mid=(start+end)/2;
    mergesort(input,start,mid);
    mergesort(input,mid+1,end);
    merge(input,start,end,mid);
}