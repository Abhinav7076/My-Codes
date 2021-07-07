class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      queue<Node*> q;
      if(!node) return v;
      
      q.push(node);
      
      while(!q.empty()){
          Node* t = q.front();
          v.push_back(t->data);
          
          if(t->left)
          q.push(t->left);
          if(t->right)
          q.push(t->right);
          
          q.pop();
      }
      
      return v;
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        v=levelOrder(root);
        sort(v.begin(),v.end());
    
        if(v.size()==0)
        return NULL;
        
        return construct(v,0,v.size()-1);
    }
    Node* construct(vector<int> v,int left,int right){
        if(left>right)
        return NULL;
        int mid=left+(right-left)/2;
        Node* node = new Node(v[mid]);
        node->left=construct(v,left,mid-1);
        node->right=construct(v,mid+1,right);
        return node;
    }
};