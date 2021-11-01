class Solution
{
    public:
    struct Node
     {
         int freq;
     //    char ch;
         Node* left;
         Node* right;
         
         Node(int f)
         {
             this->freq=f;
           
             this->left=NULL;
             this->right=NULL;
         }
         
     };
     
     struct mycomp
     {
        bool operator()(Node* n1,Node* n2)
        {
            return n1->freq>n2->freq;// max element pushed first , heap at top min elemnt 
        }
     };
     void print_codes(Node* root, string str, vector<string> &ans)
     {
         if(root==NULL)
         {
             return ;
         }
         
         if(root->left==NULL && root->right==NULL)
         {
             ans.push_back(str);
            
         }
         
         print_codes(root->left,str+"0",ans);
         print_codes(root->right,str+"1",ans);
     }
        vector<string> huffmanCodes(string S,vector<int> f,int N)
        {
            // Code here
             priority_queue<Node* ,vector<Node*> ,mycomp> pq;
             int n=N;
             for(int i=0;i<n;i++)
             {
                 Node* newnode=new Node(f[i]);
                 pq.push(newnode);
             }
             
             while(pq.size()>1)
             {
                 Node* l=pq.top();
                 pq.pop();
                 Node* r=pq.top();
                 pq.pop();
                 Node* newnode=new Node(l->freq+r->freq);
                 newnode->left=l;
                 newnode->right=r;
                 pq.push(newnode);
                 
             }
             vector<string> ans;
             Node* root=pq.top();
             print_codes(root, "",ans);
             return ans;
        }
};