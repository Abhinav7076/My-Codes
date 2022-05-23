// C++ implementation to find the level
// having maximum number of Nodes
#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer
to left child and a pointer to right
child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// function to find the level
// having maximum number of Nodes
int maxNodeLevel(Node *root)
{
	if (root == NULL)
		return -1;

	queue<Node *> q;
	q.push(root);

	// Current level
	int level = 0;

	// Maximum Nodes at same level
	int max = INT_MIN;

	// Level having maximum Nodes
	int level_no = 0;

	while (1)
	{
		// Count Nodes in a level
		int NodeCount = q.size();

		if (NodeCount == 0)
			break;

		// If it is maximum till now
		// Update level_no to current level
		if (NodeCount > max)
		{
			max = NodeCount;
			level_no = level;
		}

		// Pop complete current level
		while (NodeCount > 0)
		{
			Node *Node = q.front();
			q.pop();
			if (Node->left != NULL)
				q.push(Node->left);
			if (Node->right != NULL)
				q.push(Node->right);
			NodeCount--;
		}

		// Increment for next level
		level++;
	}

	return level_no;
}

// Driver program to test above
int main()
{
	// binary tree formation
	struct Node *root = newNode(2);	 /*	 2	 */
	root->left	 = newNode(1);	 /*	 / \ */
	root->right	 = newNode(3);	 /*	 1	 3	 */
	root->left->left = newNode(4);	 /* / \ \ */
	root->left->right = newNode(6);	 /* 4	 6 8 */
	root->right->right = newNode(8); /*	 /	 */
	root->left->right->left = newNode(5);/*	 5	 */

	printf("Level having maximum number of Nodes : %d",
			maxNodeLevel(root));
	return 0;
}
