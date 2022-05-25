// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int f=1;
    int height(Node* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l-r)>1) f=0;
        return (max(l,r) + 1);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        height(root);
        return f;
    }
};

// Time compelxity = O(n)

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