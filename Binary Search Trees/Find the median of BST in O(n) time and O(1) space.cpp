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
float findMedian(struct Node *root)
{
      //Code here
      vector<int> v = levelOrder(root);
      sort(v.begin(), v.end());
      if(v.size()%2==1)
      return v[v.size()/2];
      else
      return (float)(v[v.size()/2] + v[v.size()/2 -1])/2;
}

// O(1) solution
/* Function to count nodes in a  binary search tree
   using Morris Inorder traversal*/
int counNodes(struct Node *root)
{
    struct Node *current, *pre;
 
    // Initialise count of nodes as 0
    int count = 0;
 
    if (root == NULL)
        return count;
 
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Count node if its left is NULL
            count++;
 
            // Move to its right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
 
            while (pre->right != NULL &&
                   pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its
               inorder predecessor */
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to
               restore the original tree i.e., fix
               the right child of predecssor */
            else
            {
                pre->right = NULL;
 
                // Increment count if the current
                // node is to be visited
                count++;
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
 
    return count;
}
 
 
/* Function to find median in O(n) time and O(1) space
   using Morris Inorder traversal*/
int findMedian(struct Node *root)
{
   if (root == NULL)
        return 0;
 
    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;
 
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;
 
            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count+1)/2)
                return prev->data;
 
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (prev->data + current->data)/2;
 
            // Update prev for even no. of nodes
            prev = current;
 
            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to restore the original
              tree i.e., fix the right child of predecssor */
            else
            {
                pre->right = NULL;
 
                prev = pre;
 
                // Count current node
                currCount++;
 
                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return current->data;
 
                else if (count%2==0 && currCount == (count/2)+1)
                    return (prev->data+current->data)/2;
 
                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;
 
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}