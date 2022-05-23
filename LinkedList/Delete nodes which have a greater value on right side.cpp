Node *compute(Node *head)
    {
        // your code goes here
        if (!head || !head->next) return head;  // Base Case.
        Node* x = compute(head->next);
        (head->data >= x->data) ? head->next = x : head = x;
        return head;
        
    }
    
class Solution
{
    public:
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
    Node *compute(Node *head)
    {
        // your code goes here
        Node* rev = reverseList(head);
        int ma = INT_MIN;
        Node* cur = NULL, *start;
        while(rev!=NULL){
            if(rev->data >= ma){
                if(cur == NULL){
                    cur = new Node(rev->data);
                    start = cur;
                }
                else{
                    cur->next = rev;
                    cur = cur->next;
                }
                ma = rev->data;
            }
            rev = rev->next;
        }
        cur->next = NULL;
        return reverseList(start);
        
    }
    
};
//
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        vector<int> vv;
        while(head!=NULL){
            vv.push_back(head->data);
            head = head->next;
        }
        vector<int> v;
        int max= 0;
        for(int i=vv.size()-1;i>=0;i--){
            if(vv[i] >= max){
                max=vv[i];
                v.push_back(max);
            }
        }
        reverse(v.begin(), v.end());
        if(v.size()>0){
        Node* head2 = new Node(v[0]);
    //return head2;
    Node* head_copy = head2;
    for(int i=1;i<v.size();i++){
        head2->next = new Node(v[i]);
        head2 = head2->next;
    }
    return head_copy;
    }
    else return NULL;
    }
    
};