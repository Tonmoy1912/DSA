//it return the mid node of a linked list. 
//if length is even then it return the first mid node
Node *midPoint(Node *head){
    if(head==NULL){
        return head;
    }
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}