//bottom up approach
class Solution {
  public:
   bool palin(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[s.length()-1-i])
        return false;
    }
    return true;
    }
    string longestPalin (string s) {
        // code here
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i == n or j == n)
                dp[i][j] = 0;
                else if(s[i] == s2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
                else
                dp[i][j] = 0;
            }
        }
     
    
    int ma=0,index=0;
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]>ma){
                    string dummy=s.substr(i,dp[i][j]);
                    if(palin(dummy)){
                        ma=dp[i][j];
                        index=i;
                        ans=dummy;
                    }
                        
                    
                    // cout<<ma<<" "<<s.substr(0+index-ma,ma)<<endl;
                    
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return ans;
    }
};