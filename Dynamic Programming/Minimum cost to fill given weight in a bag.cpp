class Solution{
		
	int dp[1001][1001];
	int solve(int cost[], int wt[], int n,int w){
	    if(n==0 and w==0)
	    return 0;
	    
	    if(n==0)
	    return 1e9;
	    
	    if(w==0)
	    return 0;
	    
	    if(dp[n][w]!=-1)
	    return dp[n][w];
	    
	    if(w-wt[n-1] < 0 or cost[n-1]==-1)
	    return dp[n][w]= solve(cost,wt,n-1,w);
	    
	    
	    return dp[n][w] = min(solve(cost, wt, n, w-wt[n-1]) + cost[n-1] , solve(cost,wt,n-1,w));
	    
	    
	}

	public:
	int minimumCost(int cost[], int n, int w) 
	{ 
        // Your code goes here
        dp[n+1][w+1];
        int wt[n];
        for(int i=0;i<n;i++)
        wt[i] = i+1;
        memset(dp,-1,sizeof(dp));
        
        
        int x = solve(cost,wt,n,w);
        if(x>=1e9)
        return -1;
        return x;
	} 
};