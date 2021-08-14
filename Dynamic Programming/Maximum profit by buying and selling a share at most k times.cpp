class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        int dp[k+1][n];
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=k;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=k;i++){
            int ma=INT_MIN;
            for(int j=1;j<n;j++){
                if(dp[i-1][j-1] - a[j-1] > ma)
                ma=dp[i-1][j-1]- a[j-1];
                
                dp[i][j] = max(ma + a[j], dp[i][j-1]);
            }
        }
        
        return dp[k][n-1];
    }
};