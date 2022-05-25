// Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> v;
   
   if(!root) return v;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int size = q.size();
       v.push_back(q.front()->data);
       while(size--){
           Node* t = q.front();
           q.pop();
           if(t->right)
           q.push(t->right);
           
           if(t->left)
           q.push(t->left);
       }
   }
   return v;
    }
};