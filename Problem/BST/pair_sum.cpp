#include<vector>
void treeToVector(BinaryTreeNode<int> *root,vector<int> *arr){
    if(root==NULL){
        return;
    }
    treeToVector(root->left,arr);
    arr->push_back(root->data);
    treeToVector(root->right,arr);
}

void print(vector<int> *arr,int sum){
    int size=arr->size();
    int i=0,j=size-1;
    while(i<j){
        int k=arr->at(i)+arr->at(j);
        if(k<sum){
            i++;
        }
        else if(k>sum){
            j--;
        }
        else{
            cout<<arr->at(i++)<<" "<<arr->at(j--)<<endl;
        }
    }
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    vector<int> *arr=new vector<int>;
    treeToVector(root,arr);
    //sort(arr,0,arr->size()-1);
    print(arr,s);
    
}