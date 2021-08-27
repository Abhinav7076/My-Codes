long long int dp[1001][1001];

long long int solve(int S[],int m,int n){
    if(m==-1 and n>0)
    return 0;
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    
    if(dp[m][n]!=-1)
    return dp[m][n];
    
    return dp[m][n] = solve(S,m,n-S[m]) + solve(S,m-1,n);
}


long long int count(long long int n)
{
	
	int S[3] = {3,5,10};
	
	dp[3][n+1];
    memset(dp,-1,sizeof(dp));
    return solve(S,2,n);
}