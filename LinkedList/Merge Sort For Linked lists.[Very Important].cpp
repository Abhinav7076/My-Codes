class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
    vector<int> v;
    while(head!=NULL){
        v.push_back(head->data);
        head = head->next;
    }
    sort(v.begin(), v.end());

    if(v.size()>0){
    Node* head = new Node(v[0]);
    //return head;
    Node* head_copy = head;
    for(int i=1;i<v.size();i++){
        head->next = new Node(v[i]);
        head = head->next;
    }
    return head_copy;
    }
    else return NULL;
    }
};