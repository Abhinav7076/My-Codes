vector<int> levelOrder(Node *root){
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* t= q.front();
        v.push_back(t->data);
        q.pop();
        if(t->left)
        q.push(t->left);
        if(t->right)
        q.push(t->right);
    }
    sort(v.begin(), v.end());
    return v;
}

Node* construct(Node* root, vector<int> v, int left, int right){
    if(left>right)
    return NULL;
    int mid=left+(right-left)/2;
    Node* res = new Node(v[mid]);
    res->left = construct(res, v, left, mid-1);
    res->right = construct(res, v, mid+1, right);
    return res;
    
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> v;
	v = levelOrder(root);
	return construct(root, v, 0, v.size()-1);
}