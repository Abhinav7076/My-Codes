void levelOrder(Node* root, unordered_map<int, bool> &u){
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            u[t->data]=true;
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        return;
    }
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    unordered_map<int, bool> u1;
    unordered_map<int, bool> u2;
    levelOrder(root1, u1);
    levelOrder(root2, u2);
    
    unordered_map<int, bool>::iterator it;
    int c=0;
    for(it=u1.begin(); it!=u1.end(); it++){
        // cout<<it->first<<" ";
        if(u2[x-(it->first)])
        c++;
    }
    return c;
    
}