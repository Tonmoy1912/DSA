//it reverse a given linked list and return the head of the reversed linked list
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *smallout=reverseLinkedListRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallout;
}

//it create a reverse linked list
Node *reverse(Node *head,Node *prehead){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        Node *newnode=new Node(head->data);
        newnode->next=prehead;
        return newnode;
    }
    Node *newnode=new Node(head->data);
    newnode->next=prehead;
    return reverse(head->next,newnode);
}

//it reverse a linked list iteratively
Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *i=head;
    Node *j=head->next;
	Node *k;
    while(j->next!=NULL){
        k=j->next;
        j->next=i;
        i=j;
        j=k;
    }
    j->next=i;
    head->next=NULL;
    return j;
}