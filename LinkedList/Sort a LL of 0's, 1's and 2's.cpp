class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
    vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
    
    sort(v.begin(), v.end());
    Node* head2 = new Node(v[0]);
    //return head2;
    Node* head_copy = head2;
    for(int i=1;i<v.size();i++){
        head2->next = new Node(v[i]);
        head2 = head2->next;
    }
    return head_copy;   
    }
};