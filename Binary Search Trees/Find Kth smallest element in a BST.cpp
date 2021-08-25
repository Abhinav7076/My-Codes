class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    vector<int> levelOrder(Node* root){
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            v.push_back(t->data);
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        return v;
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        vector<int> v = levelOrder(root);
        sort(v.begin(), v.end());
        if(K>v.size())
        return -1;
        return v[K-1];
    }
};
