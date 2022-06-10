#include<queue>
#include<iostream>
using namespace std;
class BST {
    
    BinaryTreeNode<int> *root;
    
    bool search(BinaryTreeNode<int> *node,int data){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        if(data<node->data){
            return search(node->left,data);
        }
        else{
            return search(node->right,data);
        }
        
    }
    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int> *node,int data){
        if(node==NULL){
            BinaryTreeNode<int>* newroot=new BinaryTreeNode<int>(data);
            return newroot;
        }
        else if(node->data>=data){
            BinaryTreeNode<int>* newroot=insert(node->left,data);
            node->left=newroot;
            return node;
        }
        // else if(data==node->data){
        //     BinaryTreeNode<int>* newroot=new BinaryTreeNode<int>(data);
        //     newroot->left=node->left;
        //     newroot->right=node->right;
        //     node->right=NULL;
        //     node->left=newroot;
        //     return node;
        // }
        else{
            BinaryTreeNode<int>* newroot=insert(node->right,data);
            node->right=newroot;
            return node;
        }
    }
    

    
    BinaryTreeNode<int>* findSmallest(BinaryTreeNode<int> *node){
        if(node==NULL){
            return NULL;
        }
        if(node->left==NULL){
            return node;
        }
        return (node->left);
    }
    
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return NULL;
		}

		if (data > node->data) {
			node->right = deleteData(data, node->right);
			return node;
		} else if (data < node->data) {
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if (node->right == NULL) {
				BinaryTreeNode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp; 
			} else {
				BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteData(rightMin, node->right);
				return node;
			}
		}
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
        }
        else{
            cout<<"L:"<<front->left->data<<",";
            pendingNode.push(front->left);
        }
        if(front->right==NULL){
        }
        else{
            cout<<"R:"<<front->right->data;
            pendingNode.push(front->right);
        }
        cout<<endl;
    }
}
    
    void printRecursively(BinaryTreeNode<int> *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        printRecursively(root->left);
        printRecursively(root->right);
    }
   public:
    BST() { 
        root==NULL;
    }

    void remove(int data) { 
        root=deleteData(data,root);
        
    }

    void print() { 
        printRecursively(root);
    }

    void insert(int data) { 
        root=insert(root,data);
    }

    bool search(int data) {
        return search(root,data);
    }  
};