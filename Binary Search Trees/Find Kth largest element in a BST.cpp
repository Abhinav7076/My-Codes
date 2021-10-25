// The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
// The reverse inorder traversal traverses all nodes in decreasing order,
// i.e, visit the right node then centre then left and continue traversing the nodes recursively.
// While doing the traversal, keep track of the count of nodes visited so far.
// When the count becomes equal to k, stop the traversal and print the key.

void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;
 
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);
 
    // Increment count of visited nodes
    c++;
 
    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }
 
    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}
 
// Function to find k'th largest element
void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;
 
    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}

//another
class Solution
{
    public:
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
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v = levelOrder(root);
        sort(v.begin(), v.end(), greater<int>());
        return v[K-1];
    }
};