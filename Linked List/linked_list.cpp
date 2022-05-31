#include<iostream>
using namespace std;

//sturcture of node of linked list
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// it print the entire linked list
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// it return the length the linked list
int len(Node *head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
