vector<int> reverseLevelOrder(Node *node)
{
    // code here
    vector<int> v;
      queue<Node*> q;
      if(!node) return v;
      
      q.push(node);
      while(!q.empty()){
          Node* t = q.front();
          v.push_back(t->data);
          
          
          if(t->right)
          q.push(t->right);
          if(t->left)
          q.push(t->left);
          
          q.pop();
      }
      reverse(v.begin(), v.end());
      return v;
}