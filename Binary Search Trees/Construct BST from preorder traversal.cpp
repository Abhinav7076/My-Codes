class Solution {
public:
    int idx=0;
    unordered_map<int,int> u;
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int lb, int ub){
        if(ub<lb)
            return NULL;
        TreeNode* res = new TreeNode(preorder[idx++]);
        if(ub == lb)
            return res;
        int mid = u[res->val];
        res->left = solve(inorder, preorder, lb, mid-1);
        res->right = solve(inorder, preorder, mid+1, ub);
        return res;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx=0;
        u.clear();
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        for(int i=0;i<preorder.size();i++)
            u[inorder[i]] = i;
        return solve(inorder,preorder,0,preorder.size()-1);
    }
};