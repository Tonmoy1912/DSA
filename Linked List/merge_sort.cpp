//this sort a list with merge sort algo and return the head of the sorted linked list
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *temp1=head1,*temp2=head2,*ans=NULL,*temp=NULL;
    //ans=head of new sorted linked list
    //temp=tail of new sorted linked list
    while(temp1!=NULL&&temp2!=NULL){
        if(ans==NULL){
            if((temp1->data)<(temp2->data)){
                ans=temp1;
                temp=ans;
                temp1=temp1->next;
            }
            else{
                ans=temp2;
                temp=ans;
                temp2=temp2->next;
            }
        }
        else{
            if((temp1->data)<(temp2->data)){
                temp=temp->next=temp1;
                
                temp1=temp1->next;
            }
            else{
                temp=temp->next=temp2;
                
                temp2=temp2->next;
            }
        }
    }
    if(temp1==NULL){
        temp->next=temp2;
    }
    else{
        temp->next=temp1;
    }
    return ans;
}

Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    Node *mid=midPoint(head);
    Node *half1=head;
    Node *half2=mid->next;
    mid->next=NULL;
    half1=mergeSort(half1);
    half2=mergeSort(half2);
    Node *finalhead=mergeTwoSortedLinkedLists(half1,half2);
    return finalhead;
}
