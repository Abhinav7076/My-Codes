//top down approach
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        // memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0)
                dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1] )
                dp[i][j] = dp[i-1][j-1]+1;
                else
                dp[i][j] = 0;
            }
        }
        int ma=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ma=max(ma,dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ma;
    }
};

//bottom up approach
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i == n or j == m)
                dp[i][j] = 0;
                else if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
                else
                dp[i][j] = 0;
            }
        }
        int ma = INT_MIN;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)
                ma = max(ma, dp[i][j]);
        }
        return ma;
    }
};