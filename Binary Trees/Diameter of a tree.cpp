class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int ma=0;
    int func(Node* node){
        if(!node) return 0;
        int x = func(node->left);
        int y = func(node->right);
        ma = max(ma, x+y+1);
        return (max(x,y)+1);
    }
    int diameter(Node* root)
    {
    // Your code here
    if(!root) return 0;
    int x = func(root);
    return ma;
    }

};