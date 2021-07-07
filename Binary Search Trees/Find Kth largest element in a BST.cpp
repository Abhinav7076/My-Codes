class Solution
{
    public:
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
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v = levelOrder(root);
        sort(v.begin(), v.end(), greater<int>());
        return v[K-1];
    }
};