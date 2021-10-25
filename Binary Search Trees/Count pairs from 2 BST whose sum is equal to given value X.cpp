class Solution
{private: 
public:
bool search(int target,Node* node){
   if(node==nullptr) return false;
   while(node!=nullptr)
   {
       if(target>node->data)
       {
      if(node->right) node=node->right;
       }
      else if(target==node->data) return true;
      else {
          if(node->left) node=node->left;
      }
   }
}
int treetrav(Node* rt,Node* rt2,int x){
   static int count=0;
   if(rt==nullptr) return 0;
   treetrav(rt->left,rt2,x);
   search(x-rt->data,rt2)==true?count++:count=count;
   treetrav(rt->right,rt2,x);
   return count;
}

int countPairs(Node* root1, Node* root2, int x)
{
 return treetrav(root1,root2,x);
 
}
};


void levelOrder(Node* root, unordered_map<int, bool> &u){
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            u[t->data]=true;
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        return;
    }
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    unordered_map<int, bool> u1;
    unordered_map<int, bool> u2;
    levelOrder(root1, u1);
    levelOrder(root2, u2);
    
    unordered_map<int, bool>::iterator it;
    int c=0;
    for(it=u1.begin(); it!=u1.end(); it++){
        // cout<<it->first<<" ";
        if(u2[x-(it->first)])
        c++;
    }
    return c;
    
}