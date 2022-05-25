// saare roots ko uthao aur fir khali kardo
// Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
vector<int> leftView(Node *root)
{
   // Your code here
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
           if(t->left)
           q.push(t->left);
           if(t->right)
           q.push(t->right);
       }
   }
   return v;
}
