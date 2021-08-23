//efficient solution
Node* lca(Node* root, int a,int b){
    if(!root) return NULL;
    if(root->data == a or root->data == b)
    return root;
    Node* l =lca(root->left, a, b);
    Node* r =lca(root->right, a, b);
    if(l and r) return root;
    if(l) return l;
    else return r;
}

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    bool descendent(Node* node, int n1, int n2)
    {
      //Your code here
      //cout<<"entered "<<node->data<<endl;
      queue<Node*> q;
      if(!node) return false;
      
      q.push(node);
      int f1=0,f2=0;
      while(!q.empty()){
          Node* t = q.front();
          //cout<<t->data<<" ";
          if(f1==1 and f2==1)
          return true;
          if(f1==0 and t->data == n1)
          f1=1;
          if(f2==0 and t->data == n2)
          f2=1;
          
          
          if(t->left)
          q.push(t->left);
          if(t->right)
          q.push(t->right);
          
          q.pop();
      }
      if(f1==1 and f2==1)
          return true;
      return false;
    }
    Node* lca(Node* node ,int n1 ,int n2 )
    {
      //Your code here
      int ancestor=-1;
      Node* no = NULL;
      queue<Node*> q;
      if(!node) return NULL;
      
      q.push(node);
      
      while(!q.empty()){
          Node* t = q.front();
          if(descendent(t, n1, n2)){
          ancestor = t->data;
          no = t;
          }
          
          if(t->left)
          q.push(t->left);
          if(t->right)
          q.push(t->right);
          
          q.pop();
      }
      if(ancestor==-1)
      return NULL;
      //cout<<ancestor;
      return no;
      
     
    }
};
