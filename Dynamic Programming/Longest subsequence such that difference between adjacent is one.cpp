class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        int dp[n];
        fill(dp, dp+n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(a[i]-a[j]) == 1){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ma=0;
        for(int i=0;i<n;i++){
            if(dp[i] > ma)
            ma = dp[i];
        }        
        return ma;
        
    }
};
