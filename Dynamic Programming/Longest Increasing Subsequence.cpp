//Solution of O(N logN)
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n+1];
       
       fill(dp,dp+n+1,INT_MAX);
       dp[0] = INT_MIN;
       
       for(int i=0;i<n;i++){
           int idx = upper_bound(dp,dp+n+1,a[i]) - dp;
           if(a[i] > dp[idx-1] and a[i] < dp[idx] )
           dp[idx] = a[i];
           
       }
       int ma;
       for(int i=n;i>=1;i--){
        //   cout<<dp[i]<<" ";
        if(dp[i]!=INT_MAX){
            ma=i;
            break;
        }
       }
       
       return ma;
       
    }
};

//Solution of O(N^2)
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n];
       memset(dp,1,sizeof(dp));
       
       for(int i=0;i<n;i++){
           dp[i]=1;
       }
       
       for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
               if(a[j] < a[i]){
                   dp[i] = max(dp[i], dp[j]+1);
               }
           }
       }
       int ma=dp[0];
       for(int i=1;i<n;i++){
        //   cout<<dp[i]<<" ";
           ma=max(ma,dp[i]);
       }
       
       return ma;
       
    }
};