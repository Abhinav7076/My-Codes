class Solution{
public:
    int palindromicPartition(string s)
    {
        // code here
        int n=s.length();
        bool dp[n][n];
        for(int gap = 0;gap<n;gap++){
             for(int i=0,j=gap;j<s.length();i++,j++){
                if(gap==0)
                dp[i][j] = true;
                else if(gap == 1){
                    if(s[i]==s[j])
                    dp[i][j] = true;
                    else
                    dp[i][j] = false;
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1] == true){
                        dp[i][j] = true;
                    }
                    else
                    dp[i][j] = false;
                    }
                }
            }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        int arr[n];
        arr[0] = 0;
        for(int j=1;j<n;j++){
            if(dp[0][j])
            arr[j] = 0;
            else{
            int mi=INT_MAX;
            for(int i=j;i>=1;i--){
                // cout<<i<<" "<<j<<" "<<s.substr(i,j)<<endl;
                if(dp[i][j])
                    mi = min(mi, arr[i-1]);
            }
            arr[j] = mi + 1 ;
            }
        }
        // for(int i=0;i<n;i++)
        // cout<<arr[i]<<" ";
        return arr[n-1];
    }
};