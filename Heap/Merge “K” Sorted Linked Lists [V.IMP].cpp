class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
            Node* ans;
            Node* head;
            vector<int> v;
            
            for(int i=0;i<K;i++){
                Node* head = arr[i];
                while(head!=NULL){
                    v.push_back(head->data);
                    head=head->next;
                }
            }
            sort(v.begin(), v.end());
            
            ans = new Node(v[0]);
            head = ans;
            for(int i=1;i<v.size();i++){
                ans->next = new Node(v[i]);
                ans=ans->next;
            }
            ans->next=NULL;
            return head;
    }
};

//method 2
//can be done with priority queue