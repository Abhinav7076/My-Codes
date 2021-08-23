class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
        
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<v.size();i++){
            if(v[i]%2==1)
            odd.push_back(v[i]);
            else
            even.push_back(v[i]);
        }
        for(int i=0;i<even.size();i++){
            v[i] = even[i];
        }
        for(int i=0;i<odd.size();i++){
            v[i+even.size()] = odd[i];
        }

        
        if(v.size()>0){
    Node* head2 = new Node(v[0]);
    //return head;
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
