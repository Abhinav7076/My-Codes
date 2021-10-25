unordered_map<string, pair<Node*,int> > u;
vector<Node*> ans;
    string solve(Node* root){
        if(!root)
        return "$";
        
        if(!root->left and !root->right){
            string s="";
            s = to_string(root->data);
            if(u[s].second == 1)
            ans.push_back(u[s].first);
            u[s]={root, u[s].second+1};
            return s;
        }
        string s="";
        s = s + to_string(root->data);
        s = s + "*" + solve(root->left);
        s = s + "*" + solve(root->right);
        if(u[s].second == 1)
        ans.push_back(u[s].first);
        u[s]={root, u[s].second+1};
        return s;
    }

    
vector<Node*> printAllDups(Node* root)
{
    // Code here
     ans.clear();
     if(!root)
        return {NULL};
     u.clear();
     solve(root);
     
     return ans;
}