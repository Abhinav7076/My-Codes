class Solution
{
    public:
    int dp[10001];
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y, int z){
        // cout<<n<<" "<<dp[n]<<"\n";
        
        if(n==0)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int m1=INT_MIN,m2=INT_MIN,m3=INT_MIN;
        // m1=m2=m3 = INT_MIN;
        
        if(n>=x)
        m1= solve(n-x,x,y,z);
        if(n>=y)
        m2 = solve(n-y,x,y,z);
        if(n>=z)
        m3= solve(n-z,x,y,z);
        dp[n] = 1 + max(m1,max(m2,m3));
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        int ans = solve(n,x,y,z);
        if(ans<0)
        return 0;
        return ans;
    }
};
