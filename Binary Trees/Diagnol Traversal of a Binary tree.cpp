vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> v;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp){
           if(temp->left)
           q.push(temp->left);
           v.push_back(temp->data);
           temp = temp->right;
       }
   }
   return v;
}