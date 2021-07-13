class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1)
        return k;
        if(n>2 and k==1)
        return 0;
        if(n<=2 and k==1)
        return 1;
        
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1] = k;
        long long ll = k;
        long long lk = k*(k-1);
        dp[2] = k + k*(k-1);
        // cout<<"2 "<<dp[2]<<endl;
        for(int i=3;i<=n;i++){
            ll=lk;
            lk=dp[i-1]*1L*(k-1)%1000000007;
//            lk = (((dp[i-1])%1000000007)*((k-1)%1000000007))%1000000007;
            dp[i] = (ll+lk)%1000000007;
            // cout<<"i "<<dp[i]<<"\n";
        }
        return dp[n];
    }
};
