bool isCircular(Node *head)
{
   // Your code here
   unordered_map<Node*, bool> u;
   while(head!=NULL){
       if(!u[head]){
           u[head] = true;
           head = head->next;
       }
       else
        return true;
   }
   return false;
}