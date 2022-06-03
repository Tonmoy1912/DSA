#include<iostream>
using namespace std;


template <typename T>
class Node {
	public :
	T data;
	Node<T> *next;

	Node(T data) {
    	this->data = data;
    	next = NULL;
	}
};


template <typename T>
class queue {
	
    Node<T> *head;
    Node<T> *tail;
    int size;
    
   public:
    queue() {
		
    	head=tail=NULL;
        size=0;
	}
	
	int getSize() {
		
        return size;
	}

    bool isEmpty() {
		
        return size==0;
	}

    void enqueue(T data) {
		
        Node<T> *newnode=new Node<T>(data);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
        
	}

    T dequeue() {
        
        if(size==0){
            cout<<"The queue is empty"<<endl;
            return 0;
        }
        Node<T> *temp=head;
        T ans=head->data;
        head=head->next;
        delete temp;
        size--;
        if(size==0){
            tail=NULL;
        }
        return ans;
    }

    T front() {
        
        if(size==0){
            cout<<"The queue is empty"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }
};
