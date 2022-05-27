// Given a binary tree, the task is to flip the binary tree towards the right direction that is clockwise. See the below examples to see the transformation.
// In the flip operation, the leftmost node becomes the root of the flipped tree and its parent becomes its right child and the right sibling becomes its left child and the same should be done for all left most nodes recursively. 

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