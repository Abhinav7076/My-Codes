class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    if (S.find('0') == string::npos)
        return -1;
        
        if (S.find('1') == string::npos)
        return S.length();
        
        
        int dp[S.length()];
        if(S[0]=='0')
        dp[0] = 1;
        else
        dp[0] = 0;
        for(int i=1;i<S.length();i++){
            if(S[i]=='1')
            dp[i] = max(0,dp[i-1]-1);
            else
            dp[i] = dp[i-1]+1;
            
        }
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<S.length();i++){
            // cout<<dp[i]<<" ";
            ma=max(ma,dp[i]);
        }
        return ma;
	}
};