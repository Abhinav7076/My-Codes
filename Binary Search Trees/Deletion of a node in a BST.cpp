// 3 cases. 4 in 3rd subcase are simple so if node to be deleted has right and left child then pick the max val from left subtree and store its value in root and then delete it from left subtree

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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(key>root->val)
            root->right = deleteNode(root->right, key);
        else if(key<root->val)
            root->left = deleteNode(root->left, key);
        else{
            if(root->right and root->left){
                int v= findMax(root->left);
                root->val = v;
                root->left = deleteNode(root->left,v);
                return root;
            }
            else if(root->left and root->right==NULL)
                return root->left;
            else if(root->right and root->left==NULL)
                return root->right;
            else
                return NULL;
        }
        return root;
         
    }
};