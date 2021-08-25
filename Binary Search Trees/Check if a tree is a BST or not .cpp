/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMax(TreeNode* root){
        int mac=INT_MIN;
        while(root!=NULL){
            mac=max(mac,root->val);
            root=root->right;
        }
        return mac;
    }
    int findMin(TreeNode* root){
        int mac=INT_MAX;
        while(root!=NULL){
            mac=min(mac,root->val);
            root=root->left;
        }
        return mac;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(root->left and findMax(root->left) >= root->val)
            return false;
        if(root->right and findMin(root->right) <= root->val)
            return false;
        
        if(!isValidBST(root->left) or !isValidBST(root->right))
            return false;
        return true;
    }
};

//other
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