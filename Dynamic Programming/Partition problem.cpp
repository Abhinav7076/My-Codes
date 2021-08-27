class Solution{
public: 
int dp[1001][1001];
    int solve(int arr[], int n, int w){
        if(w==0)
        return 1;
        if(w<0 or (n==0 and w!=0))
        return 0;
        if(dp[n][w]!=-1)
        return dp[n][w];
        
        int a,b;
        a=solve(arr,n-1,w-arr[n-1] );
        b=solve(arr,n-1,w );
        return dp[n][w] = a or b;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr,arr+N,0);
        if(sum%2==1)
        return 0;
        
        dp[N+1][sum/2+1];
        memset(dp,-1,sizeof(dp));
        solve(arr,N,(sum/2) );
        
        
    }
};
