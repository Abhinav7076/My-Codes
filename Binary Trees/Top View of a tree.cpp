// q of pair <pointer and h> and map ,agar map me value 0
// hai to update karenge nhi to nhi -2 -1 0 1 2
class Solution{
  public:
    // function should return the topView of the binary tree
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> v;
        queue<pair<Node*, int> > q;
        map<int,int> m;
        q.push({root, 0});
        while(!q.empty()){
            Node* t =q.front().first;
            int h = q.front().second;
            q.pop();
            if(m[h]==0)
            m[h] = t->data;
            if(t->left)
            q.push({t->left,h-1});
            
            if(t->right)
            q.push({t->right,h+1});
        }
        
        for(auto x:m) v.push_back(x.second);
        return v;
    }

};
