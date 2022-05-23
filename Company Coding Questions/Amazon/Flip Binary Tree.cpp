// method to flip the binary tree
Node* flipBinaryTree(Node* root)
{
    // Base cases
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL)
        return root;
 
    //  recursively call the same method
    Node* flippedRoot = flipBinaryTree(root->left);
 
    //  rearranging main root Node after returning
    // from recursive call
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;
 
    return flippedRoot;
}