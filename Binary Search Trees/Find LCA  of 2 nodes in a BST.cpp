//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int a, int b)
{
    if(!root) return NULL;
    if(root->data == a or root->data == b)
    return root;
    Node* l =LCA(root->left, a, b);
    Node* r =LCA(root->right, a, b);
    if(l and r) return root;
    if(l) return l;
    else return r;
   //Your code here
}