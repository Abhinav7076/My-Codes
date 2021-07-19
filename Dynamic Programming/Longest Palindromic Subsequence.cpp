class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int dp[n+1][n+1];
        
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==n or j== n)
                    dp[i][j] = 0;
                else if(s[i] == s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};