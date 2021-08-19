class Solution
{
    public:
    Node *reverse (Node *head)
    { 
        Node* nex;
        Node* prev = NULL;
        Node* cur = head;
        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        return prev;
    }

    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* root = head;
        
        Node* cur = head;
        int num = 0;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        
        cur->data = cur->data+1;
        // return root;
        
        Node* rev = reverse(head);
        cur = rev;
        int carry=0;
        while(cur->next!=NULL){
            if(cur->data == 10){
                cur->data = 0;
                cur->next->data += 1;
            }
            cur = cur->next;
        }
        root = reverse(rev);
        return root;
        
    }
};