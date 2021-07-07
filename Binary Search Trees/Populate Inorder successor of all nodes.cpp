class Solution
{
public:
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

    void populateNext(Node *root)
    {
        //code here
        queue<Node*> q;
        q.push(root);
        Node *root_copy = root;
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            t->next = getSuccessor(t, root_copy);
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        
        root = root_copy;

    }
};