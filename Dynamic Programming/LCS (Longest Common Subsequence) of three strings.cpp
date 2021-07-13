int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1+1][n2+1][n3+1];
    for(int i=n1;i>=0;i--){
        for(int j=n2;j>=0;j--){
            for(int k=n3;k>=0;k--){
                if(i==n1 or j==n2 or k==n3)
                dp[i][j][k] = 0;
                else if((A[i] == B[j]) and (B[j] == C[k]))
                dp[i][j][k] = 1 + dp[i+1][j+1][k+1];
                else
                dp[i][j][k] = max(dp[i+1][j][k], max(dp[i][j+1][k], dp[i][j][k+1]));
            }
        }
    }
    return dp[0][0][0];
}