struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        // return "true" if "b" is ordered
        // before "a", for example:
        return a->data > b->data;
    }
};
void flatten(Node* root)
{
    priority_queue<Node*, vector<Node*>, mycomp> p;
  //pushing main link nodes into priority_queue.
    while (root!=NULL) {
        p.push(root);
        root = root->next;
    }
   
    while (!p.empty()) {
      //extracting min
        auto k = p.top();
        p.pop();
      //printing  least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
    
}
// Time Complexity: O(N*M*log(N))

//method 2
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