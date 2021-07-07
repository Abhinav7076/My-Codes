class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')

struct Node* search(Node* root, int x)
{
    //Your code here
    if(root == NULL or root->data == x)
    return root;
    
    if(x > root->data)
    return search(root->right, x);
    
    if(x < root->data)
    return search(root->left, x);
    
}

struct Node* minValue(Node* root)
{
    // Code here
    if(root == NULL)
    return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node* getSuccessor(Node* cur, Node* root){
    if(cur->right != NULL){
            return minValue(cur->right);
        }
        else{
            struct Node* successor = NULL;
            struct Node* ancestor = root;
            while(ancestor != cur){
                if(cur->data < ancestor->data){
                    successor = ancestor;
                    ancestor = ancestor->left; 
                }
                else
                    ancestor = ancestor->right;
            }
            return successor;
        }
}

    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        
        struct Node* cur = search(root,x->data);
        if(cur == NULL)
        return NULL;
        else{
            //find successor
            return getSuccessor(cur, root);
            
            //find predecessor
            // pre = getPredecessor(cur,root);
        }
    }
};



// for predecessor
struct Node* getPredecessor(Node* cur, Node* root){
    if(cur->left != NULL){
            return maxValue(cur->left);
        }
        else{
            struct Node* predecessor = NULL;
            struct Node* ancestor = root;
            while(ancestor != cur){
                if(cur->key > ancestor->key){
                    predecessor = ancestor;
                    ancestor = ancestor->right; 
                }
                else
                    ancestor = ancestor->left;
            }
            return predecessor;
        }
}
