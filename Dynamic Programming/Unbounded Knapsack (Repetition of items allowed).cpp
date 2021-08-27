class Solution{
public:
    int dp[1001][1001];
    int solve(int n, int w, int val[], int wt[]){
        if(n==0 or w<=0)
        return 0;
        
        if(dp[n][w]!=-1)
        return dp[n][w];
        
        if(w-wt[n-1]>=0)
        return dp[n][w] = max(solve(n,w-wt[n-1],val,wt) + val[n-1], solve(n-1,w,val,wt));
        else
        return dp[n][w] = solve(n-1,w,val,wt);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp[N+1][W+1];
        memset(dp,-1,sizeof(dp));
        return solve(N,W,val,wt);
        
    }
};