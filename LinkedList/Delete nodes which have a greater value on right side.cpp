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