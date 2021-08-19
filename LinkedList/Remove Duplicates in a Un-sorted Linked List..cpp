class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     Node* root = head;
     if(!head) return NULL;
     unordered_map<int,int>  u;
     
     Node* cur = head->next;
     Node* prev = head;
     u[prev->data] = 1;
     while(cur!=NULL){
         if(u[cur->data]==0){
             u[cur->data] = 1;
             prev = prev->next;
             cur=cur->next;
         }
         else{
             prev->next = cur->next;
             cur = cur->next;
         }
     }
     return root;
    }
};
