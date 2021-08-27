class Solution{
public:
void print(vector<vector<int> > v){
    cout<<"Print\n";
    for(int i=0;i<v.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        int dp[n][n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[n-1][i] = mat[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j+1<n)
                dp[i][j] = max(dp[i][j], mat[i][j]+dp[i+1][j+1]);
                
                dp[i][j] = max(dp[i][j], mat[i][j]+dp[i+1][j]);
                
                if(j-1>=0)
                dp[i][j] = max(dp[i][j], mat[i][j]+dp[i+1][j-1]); 
            }
        }
        int ma=0;
        for(int i=0;i<n;i++){
            ma=max(ma,dp[0][i]);
        }
        return ma;
    }
};