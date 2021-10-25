// Traverse linked list using two pointers named as slow and fast. Move the fast pointer B times if it reaches the end, then no answer exists print “-1”
//  else start moving fast and slow pointers simultaneously 
// when the fast pointer reaches the end, 
// the answer will the value of the slow pointer.

int printKthfrommid(struct Node* head_ref, int k)
{
    struct Node* slow = head_ref;
    struct Node* fast = head_ref;  // initializing fast and slow pointers
     
    for( int i = 0 ; i < k ; i++ )
     {
       if(fast && fast->next)
       {
         fast = fast->next->next;  // moving the fast pointer
       }
       else
       {
         return -1;   // If no such node exists, return -1
       }
     }
      
     while(fast && fast->next)
     {
       slow  = slow->next;
       fast  = fast->next->next;
     }
      
    return slow->data;
}