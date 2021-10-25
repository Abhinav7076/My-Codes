void rotateByN(Node* &head, int pos)
{
    // return without any changes if position is 0.
    if(pos==0) return;
 
    // Finding last node.
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    // making the list circular.
    temp->next=head;
    head->pre=temp;
 
    // move head and temp by the given position.
    int count=1;
    while(count<=pos)
    {
        head=head->next;
        temp=temp->next;
        count++;
    }
 
    // now again make list un-circular.
    temp->next=NULL;
    head->pre=NULL;
}