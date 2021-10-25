class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    // Information to be returned by every
// node in bottom up traversal.
struct Info
{
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which
    // is subtree of current node
    bool isBST; // If subtree is BST
};
 
// Returns Information about subtree. The
// Information also includes size of largest
// subtree which is a BST.
Info largestBSTBT(Node* root)
{
    // Base cases : When tree is empty or it has
    // one child.
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
 
    // Recur for left subtree and right subtrees
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);
 
    // Create a return variable and initialize its
    // size.
    Info ret;
    ret.sz = (1 + l.sz + r.sz);
 
    // If whole tree rooted under current root is
    // BST.
    if (l.isBST && r.isBST && l.max < root->data &&
            r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
 
        // Update answer for tree rooted under
        // current 'root'
        ret.ans = ret.sz;
        ret.isBST = true;
 
        return ret;
    }
 
    // If whole tree is not BST, return maximum
    // of left and right subtrees
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
 
    return ret;
}
    int largestBst(Node *root)
    {
        //Your code here
        return (largestBSTBT(root).ans);
    }
};

//method 2
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root){
        if(!root)
        return {1,0,INT_MAX,INT_MIN};
        
        if(!root->left and !root->right)
        return {1,1,root->data,root->data};
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        if(l[0] and r[0]){
            if(root->data>l[3] and root->data<r[2]){
                int x = l[2];
                int y = r[3];
                if(x == INT_MAX)
                x = root->data;
                if(y == INT_MAX)
                y = root->data;
                return {1,l[1]+r[1]+1,x,y};
            }
        }
        return {0,max(l[1], r[1]),0,0};
        
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	vector<int> ans = solve(root);
    	return ans[1];
    }
};