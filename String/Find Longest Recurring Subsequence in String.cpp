class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int dp[str.length()+1][str.length()+1];
		    
		    for(int i=str.length();i>=0;i--){
		        for(int j=str.length();j>=0;j--){
		            if(i==str.length() or j==str.length())
		            dp[i][j]=0;
		            else if(str[i]==str[j] and i!=j)
		            dp[i][j]=dp[i+1][j+1] + 1;
		            else
		            dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
		        }
		    }
		    
		    return dp[0][0];
		    
		}

};
