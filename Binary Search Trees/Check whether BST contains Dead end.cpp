void levelOrder(Node* root, unordered_map<int,pair<int,int>> &range){
        queue<Node*> q;
        // vector<int> v;
        q.push(root);
        range[root->data] = {1,200};
        while(!q.empty()){
            Node* t = q.front();
            // v.push_back(t->data);
            int left = range[t->data].first;
            int right = range[t->data].second;
            q.pop();
            if(t->left){
            q.push(t->left);
            range[t->left->data] = {left, t->data-1};
            }
            if(t->right){
            q.push(t->right);
            range[t->right->data] = {t->data+1, right};
            }
        }
        return;
    }
    
    vector<int> findLeaves(Node* root){
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            
            if(t->left==NULL and t->right==NULL)
            v.push_back(t->data);
            
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        
        return v;
    }
    
bool isDeadEnd(Node *root)
{
    //Your code here
    
    unordered_map<int,pair<int,int>> range;
    levelOrder(root,range);
    vector<int> leaves =findLeaves(root);
    
    
    // cout<<endl;
    for(int i=0;i<leaves.size();i++){
        // cout<<leaves[i]<<" -> "<<range[leaves[i]].first<<" "<<range[leaves[i]].second<<endl;
        
        if((range[leaves[i]].second - range[leaves[i]].first) == 0)
            return true;
    }
    return false;
}