bool search(Node* root, int x)
{
    //Your code here
    if(root == NULL or root->data == x)
    return root;
    
    if(x > root->data)
    return search(root->right, x);
    
    if(x < root->data)
    return search(root->left, x);
    
}