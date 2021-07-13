class Solution
{
  public:
    long long int dp[1000][1000];
    
    long long int solve(int a[], int m,int n){
        if(m==-1 and n>0)
        return 0;
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        return dp[m][n] = solve(a,m,n-a[m]) + solve(a,m-1,n);
    }
    
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        dp[m][n+1];
        memset(dp,-1,sizeof(dp));
        
        return solve(S,m-1,n);
    }
};
