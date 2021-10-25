class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        queue<Node*> q;
        vector<pair<int, Node*>> v;
        
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            v.push_back({t->data, t});
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size()-1;i++){
            if(x->data == v[i].first)
            return v[i+1].second;
        }
        return NULL;
    }
};

//conventional
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
            else{  //goto nearest ancestor that is unvisited
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