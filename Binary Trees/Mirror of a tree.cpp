// simply swap the left and right link of each node. 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            swap(t->left, t->right);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return root;
    }
};