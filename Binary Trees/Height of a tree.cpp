class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
        if(root == NULL)
        return 0;
        int x = height(root->left);
        int y = height(root->right);
        return (max(x,y)+1);
    }
};

//time complexity = O(n) since visitong every node once
//space complexity = O(n) considering recursion stack