class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    memset(dp,0,sizeof(dp));
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i])
    	            dp[i] = max(dp[i], dp[j] + arr[i]);
	        }
	        if(dp[i]==0)
	        dp[i]=arr[i];
	    }
	    int ma=0;
	    for(int i=0;i<n;i++){
	   // cout<<dp[i]<<" ";
	    ma=max(ma, dp[i]);
	    }
	    return ma;
	}  
};
