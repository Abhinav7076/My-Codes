int minValue(Node* root)
{
    // Code here
    // if(root == NULL)
    // return NULL;

    int mi=INT_MAX;
    while(root!=NULL){
        mi=min(mi,root->data);
        root=root->left;
    }
    return mi;
}