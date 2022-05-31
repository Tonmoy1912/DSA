// it insertnode recursively. here i=index; index starts form 0
Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head==NULL){
        return head;
    }
    
    if(i==1){
        Node *newnode=new Node(data);
        newnode->next=head->next;
        head->next=newnode;
        return head;
    }
    if(i==0){
        Node *newnode=new Node(data);
        newnode->next=head;
        return newnode;
    }
    Node* newhead=insertNode(head->next,i-1,data);
    head->next=newhead;
    return head;
    
}

//it delete a node at index 'pos'.
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head==NULL){
        return head;
    }
    if(pos==0){
        Node *temp=head->next;
        delete head;
        return temp;
    }
    Node *newhead=deleteNode(head->next,pos-1);
    head->next=newhead;
    return head;
}