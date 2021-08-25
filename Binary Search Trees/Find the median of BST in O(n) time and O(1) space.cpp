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
float findMedian(struct Node *root)
{
      //Code here
      vector<int> v = levelOrder(root);
      sort(v.begin(), v.end());
      if(v.size()%2==1)
      return v[v.size()/2];
      else
      return (float)(v[v.size()/2] + v[v.size()/2 -1])/2;
}

