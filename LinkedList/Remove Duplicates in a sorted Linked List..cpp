Node *removeDuplicates(Node *head)
{
 // your code goes here
 Node* root = head;
 if(!head) return NULL;
 while(head->next!=NULL){
     if(head->data == head->next->data)
     head->next=head->next->next;
     else head = head->next;
 }
 return root;
}