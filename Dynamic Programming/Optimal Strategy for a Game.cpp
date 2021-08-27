long long maximumAmount(int arr[], int n) 
{
    // Your code heretraverse diagonally n 2d array
    int dp[n][n];
    
    for(int i=0,j=0;j<n;i++,j++){
            dp[i][j] = arr[i];
    }
    for(int i=0,j=1;j<n;i++,j++){
            dp[i][j] = max(arr[i],arr[j]);
    }
    
    for(int gap=2;gap<n;gap++){
        
        for(int i=0,j=gap;j<n;i++,j++){
                int v1 = arr[i] + min(dp[i+1][j-1], dp[i+2][j]);
                int v2 = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
                dp[i][j] = max(v1, v2);
            }
    }
    // int N=n;
    // for ( int x = 0; x < N; x ++ ) {
    //     for ( int y = 0; y < N; y++ ) {
    //         cout << dp[x][y] << " ";
    //     }
    //     cout<<"\n";
    // }
    return dp[0][n-1];
       

    
}