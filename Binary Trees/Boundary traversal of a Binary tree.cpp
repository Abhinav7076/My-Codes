// 1. Print the left boundary in top-down manner. 
// 2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
// …..2.1 Print all leaf nodes of left sub-tree from left to right. 
// …..2.2 Print all leaf nodes of right subtree from left to right. 
// 3. Print the right boundary in bottom-up manner.
class Solution {
public:
void printLeaves(Node* root, vector<int> &v)
{
    if (root == nullptr)
        return;
 
    printLeaves(root->left, v);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        v.push_back(root->data);
 
    printLeaves(root->right, v);
}
 
// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root, vector<int> &v)
{
    if (root == nullptr)
        return;
 
    if (root->left) {
 
        // to ensure top down order, print the node
        // before calling itself for left subtree
        v.push_back(root->data);
        printBoundaryLeft(root->left, v);
    }
    else if (root->right) {
        v.push_back(root->data);
        printBoundaryLeft(root->right, v);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root, vector<int> &v)
{
    if (root == nullptr)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right, v);
        v.push_back(root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left, v);
        v.push_back(root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to do boundary traversal of a given binary
// tree

    vector <int> boundary(Node *root)
    {
        if (root == nullptr)
        return {};
        //Your code here
        vector<int> v = {root->data};
        printBoundaryLeft(root->left, v);
 
        // Print all leaf nodes
        printLeaves(root->left, v);
        printLeaves(root->right, v);
     
        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right, v);
        
        return v;
    }
};

// Time Complexity: O(n) where n is the number of nodes in binary tree.