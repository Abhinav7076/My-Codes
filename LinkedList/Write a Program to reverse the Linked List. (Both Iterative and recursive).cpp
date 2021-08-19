class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        vector<int> v;
        Node* prev = NULL;
        Node* nex;
        Node* cur = head;
        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    
};

//vector method
#include<vector>
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
        int n = v.size();
        struct Node* rev = new Node(v[n-1]);
        struct Node* crev = rev;
        for(int i=n-2;i>=0;i--){
            struct Node* node = new Node(v[i]);
            rev->next = node;
            rev=rev->next;
        }
        return crev;
    }
    
};