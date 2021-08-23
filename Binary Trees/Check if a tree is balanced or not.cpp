int height(struct Node* node){
        // code here 
        if(!node) return 0;
        int x = height(node->left);
        int y = height(node->right);
        return (max(x,y)+1);
    }
    
bool isBalanced(Node *root)
{
    //  Your Code here
    if(!root) return false;
    
    queue<Node*> q;
      
      q.push(root);
      
      while(!q.empty()){
          Node* t = q.front();
          if(!(abs(height(t->left) - height(t->right)) <= 1))
          return false;
    
          if(t->left)
          q.push(t->left);
          if(t->right)
          q.push(t->right);
          
          q.pop();
      }
      
    return true;
    
}