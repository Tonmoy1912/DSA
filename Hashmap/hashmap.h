#include<iostream>
using namespace std;

template <typename V>
class mapNode{
    public:
    string key;
    V value;
    mapNode<V>* next;
    mapNode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~mapNode{
        delete next;
    }
};

template <typename V>
class ourmap{
    mapNode<V>** buckets;
    int count;
    int numBuckets;

    int getBucketIndex(string key){
        int x=1;
        int ans=0;
        for(int i=key.size()-1;i>=0;i--){
            ans=ans+key[i]*x;
            ans%=numBuckets;
            x*=37;
            x%=numBuckets;
        }
        ans%=numBuckets;
        return ans;
    }

    void rehash(){
        mapNode<V>** temp=buckets;
        buckets=new mapNode<V>*[2*numBuckets];
        int prevNumBuckets=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
        for(int i=0;i<prevNumBuckets;i++){
            mapNode<V>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                V valude=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<prevNumBuckets;i++){
            delete temp[i];
        }
        delete []temp;

    }

    public:
    ourmap(){
        buckets=new mapNode<V>*[5];
        for(int i=0;i<5;i++){
            buckets[i]=NULL;
        }
        count=0;
        numBuckets=5;
    } 

    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    int size(){
        return count;
    }

    void insert(string key,V value){
        int hashcode=getBucketIndex(key);
        mapNode<V>* head=buckets[hashcode];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return ;
            }
            head=head->next;
        }
        mapNode<V>* temp=buckets[hashcode];
        head=new mapNode<V>(key,value);
        head->next=temp;
        count++;
        if(1.0*count/numBuckets>0.7){
            rehash();
        }
    }

    V getValue(string key){
        int hashcode=getBucketIndex(key);
        mapNode<V>* head=buckets[hashcode];
        while(head!=NULL){
            if(head->key=key){
                return head->value;
            }
            head=head->next;
        }
        return 0;//if not found return 0 as default value
    }
    
    V remove(string key){
        int hashcode=getBucketIndex(key);
        mapNode<V>* head=buckets[hashcode];
        mapNode<V>* prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                V ans=head->value;
                mapNode<V>* temp=head->next;
                head->next=NULL;
                delete head;
                count--;
                if(prev==NULL){
                    buckets[hashcode]=temp;
                }
                else{
                    prev->next=temp;
                }
                return ans;
            }
            prev=head;
            head=head->next;
        }
        return 0;//if not found return 0 as default value
    }

};