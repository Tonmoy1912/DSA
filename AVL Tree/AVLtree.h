#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class AVLNode{
    public:
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode(int data){
        this->data=data;
        height=1;
        left=NULL;
        right=NULL;
    }
};

class AVL_tree{
    AVLNode *root;
    int size;

    int getHeight(AVLNode *head){
        if(head==NULL){
            return 0;
        }
        return head->height;
    }

    AVLNode *leftToRight(AVLNode *x){
        AVLNode *y=x->left;
        //AVLNode *t1=y->left;
        AVLNode *t2=y->right;
        //AVLNode *t3=x->right;

        y->right=x;
        x->left=t2;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }

    AVLNode *rightToLeft(AVLNode *y){
        AVLNode *x=y->right;
        //AVLNode *t1=y->left;
        //AVLNode *t3=x->right;
        AVLNode *t2=x->left;

        x->left=y;
        y->right=t2;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        x->height=max(getHeight(x->right),getHeight(x->left))+1;
        return x;
    }

    

    int getBF(AVLNode *head){
        if(head==NULL){
            return 0;
        }
        int bf=getHeight(head->left)-getHeight(head->right);
        return bf;
    }

    AVLNode *insert(AVLNode *head,int data){
        if(head==NULL){
            AVLNode *temp=new AVLNode(data);
            //cout<<"00"<<endl;
            size++;
            return temp;
        }

        if(data<head->data){
            head->left=insert(head->left,data);
        }
        if(data>head->data){
            head->right=insert(head->right,data);
        }
        head->height=max(getHeight(head->left),getHeight(head->right))+1;
        int bf=getBF(head);
        //LL
        if(bf>1&&data<head->left->data){
            return leftToRight(head);
        }
        //RR
        if(bf<-1&&data>head->right->data){
            return rightToLeft(head);
        }
        //LR
        if(bf>1&&data>head->left->data){
            head->left=rightToLeft(head->left);
            return leftToRight(head);
        }
        //RL
        if(bf<-1&&data<head->right->data){
            head->right=leftToRight(head->right);
            return rightToLeft(head);
        }
        return head;
    }

    public:
    AVL_tree(){
        root=NULL;
        size=0;
    }

    void insert(int data){
        root=insert(root,data);
    }

    void print(){
        queue<AVLNode*> q;
        q.push(root);
        while(!q.empty()){
            AVLNode *front=q.front();
            q.pop();
            cout<<front->data<<":";
            if(front->left!=NULL){
                cout<<front->left->data<<" ";
                q.push(front->left);
            }
            if(front->right!=NULL){
                cout<<front->right->data<<" ";
                q.push(front->right);
            }
            cout<<endl;
        }
    }

    void printSize(){
        cout<<"-------------"<<size<<"---------------"<<endl;
    }
    
};


// int main(){
//     AVL_tree tree;
//     for(int i=1;i<=10;i++){
//         tree.insert(i);
//     }
//     tree.print();
//     tree.printSize();
//     return 0;
// }