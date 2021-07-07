class Solution {
  public:
    int height(Node* root){
        if(root == NULL)
        return 0;
        int x = height(root->left);
        int y = height(root->right);
        return (max(x,y)+1);
    }
    bool isHeap(struct Node * root)
    {
        // code here
        if(root==NULL)
        return true;
        int h = height(root);
        // cout<<h<<endl;
        queue<pair<Node*,int>> q;
        q.push({root,1});
        int f=0;
        unordered_map<int,int> u;
        while(!q.empty()){
            Node* t = q.front().first;
            int index = q.front().second;
            q.pop();
            u[index]++;
            if(t->left){
                if(t->left->data > t->data)
                f=1;
                q.push({t->left,index+1});
            }
            if(t->right){
                if(t->right->data > t->data)
                f=1;
                q.push({t->right,index+1});
            }
        }
        for(int i=1;i<=h-1;i++){
            // cout<<i<<" "<<u[i]<<endl;
            if(u[i]!=pow(2,i-1))
            return false;
        }
        if(f==1)
        return false;
        return true;
    }
};