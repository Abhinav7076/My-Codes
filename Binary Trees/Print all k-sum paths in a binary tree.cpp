// The basic idea to solve the problem is to do a preorder 
// traversal of the given tree. We also need a container 
// (vector) to keep track of the path that led to that node. 
// At each node we check if there are any path that sums to k, 
// if any we print the path and proceed recursively to print each path.
// Below is the implementation of the same. 

// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;

// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// binary tree node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int>& path, int k)
{
	// empty node
	if (!root)
		return;

	// add current node to the path
	path.push_back(root->data);

	// check if there's any k sum path
	// in the left sub-tree.
	printKPathUtil(root->left, path, k);

	// check if there's any k sum path
	// in the right sub-tree.
	printKPathUtil(root->right, path, k);

	// check if there's any k sum path that
	// terminates at this node
	// Traverse the entire path as
	// there can be negative elements too
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];

		// If path sum is k, print the path
		if (f == k)
			printVector(path, j);
	}

	// Remove the current element from the path
	path.pop_back();
}

// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(1);
	root->left->right->left = new Node(1);
	root->right = new Node(-1);
	root->right->left = new Node(4);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(2);
	root->right->right = new Node(5);
	root->right->right->right = new Node(2);

	int k = 5;
	printKPath(root, k);

	return 0;
}

// Time Complexity: O(n*h*h)  , as maximum size of path vector can be h 