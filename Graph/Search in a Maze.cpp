class Solution{
    public:
    
    vector<string> v;
    void dfs(int i, int j, string s, vector<vector<int>> m, int n, vector<vector<int> > &visited){
        if(i<0 or j<0 or i>=n or j>=n)
        return;
        if(m[i][j]==0 or visited[i][j])
        return;
        
        if(i==n-1 and j==n-1){
            v.push_back(s);
            return;
        }
        
        visited[i][j] = 1;
        dfs(i-1,j,s+'U',m,n,visited);
        dfs(i+1,j,s+'D',m,n,visited);
        dfs(i,j-1,s+'L',m,n,visited);
        dfs(i,j+1,s+'R',m,n,visited);
        
        visited[i][j]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int> > visited(n, vector<int>(n));
        if(m[0][0]==0 or m[n-1][n-1]==0)
        return v;
        string s="";
        
        dfs(0,0,s,m,n,visited);
        sort(v.begin(),v.end());
        return v;
    }
};
