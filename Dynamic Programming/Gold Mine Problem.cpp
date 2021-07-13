class Solution{
public:
void print(vector<vector<int> > v){
    cout<<"Print\n";
    for(int i=0;i<v.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        
        
        for(int i=0;i<n;i++){
            dp[i][m-1]=M[i][m-1];
        }
        
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                if(i-1>=0)
                    dp[i][j] = max(dp[i][j], M[i][j] + dp[i-1][j+1]);
                
                dp[i][j] = max(dp[i][j], M[i][j] +  dp[i][j+1]);
                
                if(i+1<n)
                    dp[i][j] = max(dp[i][j], M[i][j] + dp[i+1][j+1]);
            }
        }
     
    
        int ma=0;
        for(int i=0;i<n;i++)
            ma=max(ma, dp[i][0]);
        
        return ma;
    }
};