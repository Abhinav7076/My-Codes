class Solution{
  public:
  void inorder(Node* root, vector<int> &v)
    {
    if (root == NULL) 
        return;
 
    inorder(root->left,v);
 
    v.push_back(root->data);
 
    inorder(root->right,v);
    }
    
    void makeMaxHeap(Node* node, vector<int> &v, int &i){
        if(node == NULL)
        return;
        makeMaxHeap(node->left,v,i);
        makeMaxHeap(node->right,v,i);
        node->data = v[i++];
        return;
    }

    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        if(root==NULL)
        return;
        vector<int> v;
        inorder(root,v);
        int i=0;
        makeMaxHeap(root, v, i);
        return;
        
    }    
};