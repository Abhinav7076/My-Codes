class Solution{
    public:
    bool isPalin(string s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1])
            return false;
        }
        return true;
    }
    
    int longestPalinSubseq(string s){
        string s2=s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        int dp[n+1][n+1];
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==n or j==n)
                dp[i][j] = 0;
                else if(s[i] == s2[j])
                dp[i][j] = dp[i+1][j+1]+1;
                else
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
    
    int countMin(string s){
    //complete the function here
    if(isPalin(s))
        return 0;
    else{
        int n = s.length();
        int l = longestPalinSubseq(s);
        return n-l;
        
    }
    return 0;
    }
};