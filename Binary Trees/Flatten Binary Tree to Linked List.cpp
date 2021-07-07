class Solution {
public:
    vector<int> v;
    void preorder(TreeNode* root)
    {
        // if the current node is empty
        if (root == nullptr) {
            return;
        }

        // Display the data part of the root (or current node)
        v.push_back(root->val);
        // Traverse the left subtree
        preorder(root->left);

        // Traverse the right subtree
        preorder(root->right);
    }

    void flatten(TreeNode* root) {
        if(!root)
            return;
        preorder(root);
        root->val = v[0];
        root->left=NULL;
        
        for(int i=1;i<v.size();i++){
            if(root->right){
                root->right->val = v[i];
                root->right->left = NULL;
            }
            else{
                TreeNode* temp= new TreeNode(v[i]);
                root->right=temp;
            }
            root=root->right;
        }
        
    }
};