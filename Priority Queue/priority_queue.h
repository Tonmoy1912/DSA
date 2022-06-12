#include<vector>
#include<bits/stdc++.h>
using namespace std;

//min Priority Queue
template <typename T>
class PriorityQueue{
    vector<T> pq;
    public:

    bool isEmpty(){
        return pq.empty();
    }

    int getSize(){
        return pq.size();
    }

    T getMin(){
        if(isEmpty()){
            cout<<"The priority queue is empty"<<endl;
            return 0;
        }
        return pq[0];
    }

    void insert(T element){
        pq.push_back(element);
        int childIndex=getSize()-1;
        int parentIndex=(childIndex-1)/2;
        while(childIndex>0&&(pq[childIndex]<pq[parentIndex])){
            swap(pq[childIndex],pq[parentIndex]);
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }

    void print(){
        int n=pq.size();
        for(int i=0;i<n;i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }

    T removeMin() {
        T ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<pq.size()){
            int minIndex=parentIndex;
            if(pq[leftChildIndex]<pq[minIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size()&&pq[rightChildIndex]<pq[minIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            swap(pq[parentIndex],pq[minIndex]);
            parentIndex=minIndex;
            leftChildIndex=2*parentIndex+1;
        	rightChildIndex=2*parentIndex+2;
        }
        return ans;
    }
};

//max Priority Queue
template <typename T>
class maxPriorityQueue {
    vector<T> pq;

   public:

    void insert(T element) {
        pq.push_back(element);
        int childIndex=pq.size()-1;
        int parentIndex=(childIndex-1)/2;
        while(childIndex>0&&pq[childIndex]>pq[parentIndex]){
            swap(pq[childIndex],pq[parentIndex]);
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }

    T getMax() {
        if(pq.empty()){
            cout<<"The priority queue is empty"<<endl;
            return 0;
        }
        return pq[0];
    }

    T removeMax() {
        if(pq.empty()){
            cout<<"The priority queue is empty"<<endl;
            return 0;
        }
        T ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<pq.size()){
            int maxIndex=parentIndex;
            if(pq[leftChildIndex]>pq[maxIndex]){
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size()&&(pq[rightChildIndex]>pq[maxIndex])){
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex){
                break;
            }
            swap(pq[parentIndex],pq[maxIndex]);
            parentIndex=maxIndex;
            leftChildIndex=2*parentIndex+1;
        	rightChildIndex=2*parentIndex+2;
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.empty();
    }
};