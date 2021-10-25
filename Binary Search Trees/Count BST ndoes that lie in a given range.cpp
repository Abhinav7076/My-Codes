int getCount(Node *root, int l, int h)
{
  // your code goes here  
  if(root == NULL)
  return 0;
  queue<Node*> q;
  q.push(root);
  int c = 0;
  while(!q.empty()){
      Node* t = q.front();
      q.pop();
      
      if(t->data >= l and t->data <=h){
        c++;
      }
    //   cout<<t->data<<" "<<c<<"\n";
      if(t->left)
      q.push(t->left);
      if(t->right)
      q.push(t->right);
  }
  
  return c;
}

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
int getCount(Node *root, int l, int h)
{
  // your code goes here
  vector<int> v= levelOrder(root);
  int c=0;
  for(int i=0;i<v.size();i++){
      if(v[i]>=l and v[i]<=h)
      c++;
  }
  return c;
}
