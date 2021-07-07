
int idx=0;
unordered_map<int,int> u;


Node* solve(int in[],int pre[],int lb,int ub){
        if(ub<lb)
        return NULL;
        Node* res = new Node(pre[idx++]);
        if(ub==lb) return res;
        int mid = u[res->data];
        res->left = solve(in,pre,lb,mid-1);
        res->right = solve(in,pre,mid+1,ub);
        return res;
    }
    
    class Solution{
        public:
        Node* buildTree(int in[],int pre[], int n)
        {
            // Code here
            idx=0;
            u.clear();
            for(int i=0;i<n;i++)
            u[in[i]] = i;
            Node* root = solve(in,pre,0,n-1);
            return root;
        }
    };