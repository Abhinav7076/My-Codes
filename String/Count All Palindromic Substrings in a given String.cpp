int CountPS(char s[], int n)
{
    //code here
    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap == 0)
            dp[i][j] = 1;
            else if(gap == 1){
                if(s[i] == s[j])
                dp[i][j] = 1;
                else
                dp[i][j] = 0;
            }
            else{
                if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1];
                else
                dp[i][j] = 0;
            }
        }
    }
    
    
    int c=0;
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(dp[i][j] == 1)
            c++;
        }
    }
    return c-n;
    
}