class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        
        long long dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        int mod = 1000000007;
        for(int i=3;i<=n;i++){
            long long tt = ((i-1)%mod * (dp[i-2]%mod))%mod;
            dp[i] = (dp[i-1]%mod + tt%mod)%mod;
        }
        return dp[n];
    }
};    
 