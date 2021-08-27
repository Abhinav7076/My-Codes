class Solution {
	public:
	int solve(vector<int>&nums, int dp[], int f){
	    for(int i=1;i<nums.size();i++){
		        if(f==1){
		        if(nums[i] > nums[i-1]){
		            dp[i] = dp[i-1] + 1;
		            f=0;
		        }
		        else
		        dp[i] = dp[i-1];
		        }
		        else{
		            if(nums[i] < nums[i-1]){
		                dp[i] = dp[i-1] + 1;
		                f=1;
		            }
		        else
		        dp[i] = dp[i-1];
		        } 
		    }
		    
		   return dp[nums.size()-1];
		  
	}
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    if(nums.size()==1)
		    return 1;
		    int dp[nums.size()];
		    dp[0]=1;
		    int f=0;
		    
		   int ans1 = solve(nums,dp,0);
		   int ans2 = solve(nums,dp,1);
		  
		  
		    
		    return max(ans1,ans2);
		    
		}

};