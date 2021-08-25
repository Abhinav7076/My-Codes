unordered_map<int,int> u;
    
Node* construct(vector<int> inorder, int preorder[],int left, int right, int &index){
    if(left>right)
    return NULL;
    Node* res = newNode(preorder[index++]);
    if(left==right)
    return res;
    int mid = u[res->data];
    res->left = construct(inorder, preorder, left, mid-1,index);
    res->right = construct(inorder, preorder, mid+1,right,index);
    return res;
    
}
Node* constructTree(int pre[], int size)
{
    //code here
    int index=0;
    u.clear();
    vector<int> inorder;
    for(int i=0;i<size;i++)
    inorder.push_back(pre[i]);
    sort(inorder.begin(), inorder.end());
    for(int i=0;i<size;i++)
        u[inorder[i]] = i;
    Node* root = construct(inorder, pre, 0, size-1,index);
    return root;
}
