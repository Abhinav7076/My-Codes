class Solution{
public:
    int find(vector<int> v){
        int ma=1;
        int dp[v.size()];
        dp[0] = 1;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1] and v[i]!=0){
                dp[i] = dp[i-1]+1;
                ma=max(ma,dp[i]);
            }
            else
                dp[i] = 1;
        }
        return ma;
    }
    void print(vector<vector<int> > v){
    cout<<"Print\n";
    for(int i=0;i<v.size();i++){
        // cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    cout<<"********\n";
}
    int maxSquare(int n, int m, vector<vector<int>> grid){
        // code here
        // print(grid);
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==0)
            dp[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            dp[i][m-1] = grid[i][m-1];
        }
        
        for(int i=0;i<m;i++){
            dp[n-1][i] = grid[n-1][i];
        }
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--)
            if(dp[i][j]==-1){
                dp[i][j]=min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1])) + 1;
            }
        }
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ma=max(ma,dp[i][j]);
        }
        
        return ma;
        
    }
};