#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T>* prev;
    Node(T data){
        this->data=data;
        prev=NULL;
    }
};

template <typename T>
class stack{
    private:
    Node<T> *head;
    int size;
    public:
    stack(){
        head=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool empty(){
        return size==0;
    }
    void push(T data){
        Node<T> *temp=new Node<T>(data);
        temp->prev=head;
        head=temp;
        size++;
    }
    T pop(){
        if(size==0){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        Node<T> *temp=head;
        T ans=temp->data;
        head=head->prev;
        delete temp;
        size--;
        return ans;
    }
    T top(){
        if(size==0){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return head->data;
    }
};
