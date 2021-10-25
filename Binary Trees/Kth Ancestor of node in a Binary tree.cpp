// using level order traversal

// The idea to do this is to first traverse the binary tree 
// and store the ancestor of each node in an array of size n. 
// For example, suppose the array is anecestor[n]. Then at 
// index i, ancestor[i] will store the ancestor of ith node. 
// So, the 2nd ancestor of ith node will be ancestor[ancestor[i]] 
// and so on. We will use this idea to calculate the kth ancestor 
// of the given node. We can use level order traversal to populate this array of ancestors.

/* C++ program to calculate Kth ancestor of given node */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// function to generate array of ancestors
void generateArray(Node *root, int ancestors[])
{
	// There will be no ancestor of root node
	ancestors[root->data] = -1;

	// level order traversal to
	// generate 1st ancestor
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left)
		{
			ancestors[temp->left->data] = temp->data;
			q.push(temp->left);
		}

		if (temp->right)
		{
			ancestors[temp->right->data] = temp->data;
			q.push(temp->right);
		}
	}
}

// function to calculate Kth ancestor
int kthAncestor(Node *root, int n, int k, int node)
{
	// create array to store 1st ancestors
	int ancestors[n+1] = {0};

	// generate first ancestor array
	generateArray(root,ancestors);

	// variable to track record of number of
	// ancestors visited
	int count = 0;

	while (node!=-1)
	{
		node = ancestors[node];
		count++;

		if(count==k)
			break;
	}

	// print Kth ancestor
	return node;
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 2;
	int node = 5;

	// print kth ancestor of given node
	cout<<kthAncestor(root,5,k,node);
	return 0;
}


//using dfs
// The idea of using DFS is to first find the given node 
// the tree and then backtrack k times to reach to the 
// kth ancestor, once we have reached the kth parent, 
// we will simply print the node and return NULL. 
v/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{
	// Base case
	if (!root)
		return NULL;
	
	if (root->data == node||
	(temp = kthAncestorDFS(root->left,node,k)) ||
	(temp = kthAncestorDFS(root->right,node,k)))
	{
		if (k > 0)	
			k--;
		
		else if (k == 0)
		{
			// print the kth ancestor
			cout<<"Kth ancestor is: "<<root->data;
			
			// return NULL to stop further backtracking
			return NULL;
		}
		
		// return current node to previous call
		return root;
	}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int k = 2;
	int node = 5;

	// print kth ancestor of given node
	Node* parent = kthAncestorDFS(root,node,k);
	
	// check if parent is not NULL, it means
	// there is no Kth ancestor of the node
	if (parent)
		cout << "-1";
	
	return 0;
}
