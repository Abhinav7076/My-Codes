bool isCircular(Node *head)
{
   // Your code here
   if(head==NULL)
   return true;
   
   Node* temp = head->next;
   unordered_map<Node*, int> u;
   while(temp!=head){
        if(temp==NULL)
        return false;
        temp = temp->next;
   }
   return true;
}