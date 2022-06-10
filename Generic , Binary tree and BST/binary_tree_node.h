#include<iostream>
#include<queue>
#include"binary_tree_node.h"
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left; 
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    } 
    // ~BinaryTreeNode{
    //     delete left;
    //     delete right;
    // }
};

BinaryTreeNode<int>* takeInput(){
    BinaryTreeNode<int>* root;
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new BinaryTreeNode<int>(data);
    BinaryTreeNode<int>* left=takeInput();
    BinaryTreeNode<int>* right=takeInput();
    root->left=left;
    root->right=right;
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<",R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout<<"Enter the left child data of "<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* leftChild=new BinaryTreeNode<int>(leftChildData);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        cout<<"Enter the right child data of "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* rightChild=new BinaryTreeNode<int>(rightChildData);
            front->right=rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL){
        cout<<-1<<endl;
        return ;
    }
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        BinaryTreeNode<int> *front=pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        if(front->left==NULL){
            cout<<"L:-1,";
        }
        else{
            cout<<"L:"<<front->left->data<<",";
            pendingNode.push(front->left);
        }
        if(front->right==NULL){
            cout<<"R:-1";
        }
        else{
            cout<<"R:"<<front->right->data;
            pendingNode.push(front->right);
        }
        cout<<endl;
    }
}