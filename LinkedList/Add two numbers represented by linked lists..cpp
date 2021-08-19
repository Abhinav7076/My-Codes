class Solution
{
    public:
    void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}
    //Function to add two numbers represented by linked list.
    struct Node* rev(struct Node* head){
        Node* nex;
        Node* cur = head;
        Node* prev = NULL;
        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        Node* rfirst = rev(first);
        Node* rsecond = rev(second);
        int carry = 0;
        Node* res = NULL;
        Node* ans;
        while(rfirst != NULL or rsecond != NULL){
            int n = (rfirst ? rfirst->data : 0) + (rsecond ? rsecond->data : 0) + carry;
            Node* temp;
            if(n>=10){
                temp = new Node(n%10);
                carry = 1;
            }
            else{
                temp = new Node(n);
                carry = 0;
            }
            if(res == NULL){
                res = temp;
                ans = res;
            }
            else{
                res->next = temp;
                res = temp;
            }
            if(rfirst)
                rfirst = rfirst->next;
            if(rsecond)
                rsecond = rsecond->next;
        }
        if(carry>0){
            Node* temp = new Node(carry);
            res->next = temp;
            res = temp;
        }
        return rev(ans);
    }
};