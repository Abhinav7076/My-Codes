class Solution{


	public:
	long long getCount(int n)
	{
		// Your code goes here
		long long dp[n+1][10];
		for(int i=0;i<=n;i++){
		    for(int j=0;j<10;j++)
    		    if(i==0)
    		    dp[0][j] = 0;
    		    else if(i==1)
    		    dp[1][j] = 1;
    		    else{
    		        if(j==0)
    		        dp[i][j] = dp[i-1][0] + dp[i-1][8];
    		        else if(j==1)
    		        dp[i][j] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4];
    		        else if(j==2)
    		        dp[i][j] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5];
    		        else if(j==3)
    		        dp[i][j] = dp[i-1][2] + dp[i-1][3] + dp[i-1][6];
    		        else if(j==4)
    		        dp[i][j] = dp[i-1][1] + dp[i-1][5] + dp[i-1][4] + dp[i-1][7];
    		        else if(j==5)
    		        dp[i][j] = dp[i-1][5] + dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
    		        else if(j==6)
    		        dp[i][j] = dp[i-1][3] + dp[i-1][5] + dp[i-1][6] + dp[i-1][9];
    		        else if(j==7)
    		        dp[i][j] = dp[i-1][7] + dp[i-1][8] + dp[i-1][4];
    		        else if(j==8)
    		        dp[i][j] = dp[i-1][7] + dp[i-1][5] + dp[i-1][8] + dp[i-1][9] + dp[i-1][0];
    		        else if(j==9)
    		        dp[i][j] = dp[i-1][6] + dp[i-1][8] + dp[i-1][9];
    		    }
		}
		long long sum=0;
		for(int j=0;j<10;j++){
		    sum+=dp[n][j];
		}
		return sum;
	}


};