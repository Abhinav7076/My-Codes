class Solution {
  public:
    int dp[1001][1001];
    int solve(string s, string t, int m,int n){
        if(m==-1)
        return n+1; // m khatam ho gaya to n+1 insert karenge
        if(n==-1)
        return m+1; // n khatam ho gaya to m+1 delete karenge
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        if(s[m] == t[n])
        return solve(s,t,m-1,n-1);
        
        int a = solve(s,t,m-1,n-1); // replace
        int b = solve(s,t,m,n-1); // insert n se ghatayenge kyunki m me inset kar diye
        int c = solve(s,t,m-1,n); // delete
        
        return dp[m][n] = 1 + min(c,min(a,b)); //1 kyunku=i upar me se ek operation kiya hai
        
        
    }
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int m = s.length();
        int n = t.length();
        return solve(s,t,m-1,n-1);
    }
};