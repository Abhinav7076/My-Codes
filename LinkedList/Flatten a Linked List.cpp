Node *flatten(Node *root)
{
   // Your code here
    vector<int> v;
    while(root!=NULL){
        Node* bott = root;
        while(bott!=NULL){
            v.push_back(bott->data);
            bott = bott->bottom;
        }
        root = root->next;
    }
    
    sort(v.begin(), v.end());
    
    Node* head = new Node(v[0]);
    //return head;
    Node* head_copy = head;
    for(int i=1;i<v.size();i++){
        head->bottom = new Node(v[i]);
        head = head->bottom;
    }
    return head_copy;
    
}