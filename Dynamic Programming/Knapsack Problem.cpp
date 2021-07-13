class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int solve(int W, int wt[], int val[], int n){
       if(n==0 or W<=0)
       return 0;
       
       if(dp[n][W]!=-1)
       return dp[n][W];
       
       if(W-wt[n-1]>=0){
       return dp[n][W] = max(solve(  W-wt[n-1], wt, val, n-1)+val[n-1], solve(  W, wt, val, n-1));
       }
       else return solve(  W, wt, val, n-1);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp[n+1][W+1];
       memset(dp,-1,sizeof(dp));
       
       return solve(  W, wt, val, n);
       
    }
};