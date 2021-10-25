Node* kthSmallest(Node* root, int& k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    // search in left subtree
    Node* left = kthSmallest(root->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;
 
    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;
 
    // else search in right subtree
    return kthSmallest(root->right, k);
}
 
// Function to find k'th largest element in BST
void printKthSmallest(Node* root, int k)
{
    // maintain index to count number of nodes processed so far
    int count = 0;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
}
 




class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    vector<int> levelOrder(Node* root){
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            v.push_back(t->data);
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        return v;
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        vector<int> v = levelOrder(root);
        sort(v.begin(), v.end());
        if(K>v.size())
        return -1;
        return v[K-1];
    }
};
