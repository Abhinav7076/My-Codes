Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    vector<int> v;
    while(head1!=NULL){
        Node* root2 = head2;
        while(root2!=NULL){
        if(head1->data == root2->data)
        v.push_back(head1->data);
        root2 = root2->next;
        }
        head1 = head1->next;
    }
    vector<int>::iterator ip;
    ip = std::unique(v.begin(), v.begin() + v.size());
    v.resize(std::distance(v.begin(), ip));
    
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