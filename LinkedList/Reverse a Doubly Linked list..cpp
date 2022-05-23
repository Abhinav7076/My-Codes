Node* reverseDLL(Node * head)
{
    //Your code here
    Node* k=NULL;
    Node* cur = head;
    while(cur!=NULL)
   {
       Node* g=cur->next;
       cur->prev=cur->next;
       cur->next=k;
        k=cur;
       cur=g;
   }
   return k;
}