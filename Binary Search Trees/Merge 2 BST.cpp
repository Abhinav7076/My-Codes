class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> levelOrder(Node *root){
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* t= q.front();
            v.push_back(t->data);
            q.pop();
            if(t->left)
            q.push(t->left);
            if(t->right)
            q.push(t->right);
        }
        sort(v.begin(), v.end());
        return v;
    }
    vector<int> merge_vec(vector<int> &a, vector<int> &b, int n, int m) {
	    // code here
	    vector<int> v;
	    int i=0,j=0;
	    while(i<n and j<m){
	        if(a[i] > b[j]){
	            v.push_back(b[j]);
	            j++;
	        }
	        else{
	            v.push_back(a[i]);
	            i++;
	        }
	    }
	    while(i<n){
	        v.push_back(a[i++]);
	    }
	    while(j<m){
	        v.push_back(b[j++]);
	    }
	    
	    return v;
	}
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a = levelOrder(root1);
       vector<int> b = levelOrder(root2);
       
       return merge_vec(a,b,a.size(),b.size());
    }
};