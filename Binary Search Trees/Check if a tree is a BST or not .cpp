class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    int findMax(Node* root){
        int mac=INT_MIN;
        while(root!=NULL){
            mac=max(mac,root->data);
            root=root->right;
        }
        return mac;
    }
    int findMin(Node* root){
        int mac=INT_MAX;
        while(root!=NULL){
            mac=min(mac,root->data);
            root=root->left;
        }
        return mac;
    }
    
    bool isBST(Node* node) 
    {
        // Your code here
      queue<Node*> q;
      if(!node) return true;
      
      q.push(node);
      
      while(!q.empty()){
          Node* t = q.front();
          //cout<<t->data<<endl;
          if(t->left){
            q.push(t->left);
            if(findMax(t->left)>=t->data)
            return false;
          }
          
          if(t->right){
            q.push(t->right);
            if(findMin(t->right)<=t->data)
            return false;
          }
          
          q.pop();
      }
      
      return true;
    }
};