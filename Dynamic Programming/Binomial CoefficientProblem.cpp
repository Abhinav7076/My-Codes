class Solution{
public:
int dp[1001][1001];
void fill_karo(int n){
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)
            dp[i][j] = 1;
            else
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%1000000007;
        }
    }
    return;
}
    int nCr(int n, int r){
        // code here
        dp[n+1][n+1];
        if(r==0 or r==n)
        return 1;
        memset(dp,0,sizeof(dp));
        fill_karo(n);
        
        
        return dp[n][r];
    }
};