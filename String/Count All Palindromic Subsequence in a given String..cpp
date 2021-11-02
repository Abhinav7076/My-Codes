//without mod
class Solution{
    public:
    /*You are required to complete below method */
    
    long long int  countPS(string s)
    {
       //Your code here
       int n = s.length();
       long long int dp[n][n];
       memset(dp, -1, sizeof(dp));
       int mod = 1e9 + 7;
       for(int gap=0;gap<n;gap++){
           for(int i=0,j=gap;j<n;i++,j++){
               if(gap==0)
               dp[i][j] = 1;
               else if(gap == 1){
                   if(s[i] == s[j])
                   dp[i][j] = 3;
                   else
                   dp[i][j] = 2;
               }
               else{
                   if(s[i] == s[j]){
                       dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1) ; 
                   }
                   else{
                       dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) ;
                   }
               }
           }
       }
           
           
           return dp[0][n-1] ;
       
    }
};

//with mod
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //Your code here
       //Your code here
       int n = s.length();
       long long int dp[n][n];
       memset(dp, -1, sizeof(dp));
       long long int mod = 1000000007;
       for(int gap=0;gap<n;gap++){
           for(int i=0,j=gap;j<n;i++,j++){
               if(gap==0)
               dp[i][j] = 1;
               else if(gap == 1){
                   if(s[i] == s[j])
                   dp[i][j] = 3;
                   else
                   dp[i][j] = 2;
               }
               else{
                   if(s[i] == s[j]){
                       dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1)%mod ; 
                   }
                   else{
                        long long a = (dp[i][j-1] + dp[i+1][j])%mod;
                        long long b = dp[i+1][j-1];
                        dp[i][j] = ((a - b) % mod + mod) % mod;
                   }
               }
           }
       }
           
           
           return dp[0][n-1] ;
    }
     
};