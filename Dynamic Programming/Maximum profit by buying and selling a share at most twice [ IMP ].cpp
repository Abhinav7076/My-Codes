//ma is Selling price and arr[i] will be our CP
//mi : CP and arr[i] is SP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=0;
        
        int ma=prices[n-1];
        int mi=prices[0];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>ma)
                ma=prices[i];
            dp[i]=max(dp[i+1],ma-prices[i]);
        }
       for(int i=1;i<n;i++){
            if(prices[i]<mi)
                mi=prices[i];
            dp[i]=max(dp[i-1],dp[i]+prices[i]-mi);
        }
        return dp[n-1];
    }
};


//another solution
class Solution {
public:
    int kmaxProfit(int k, int n, vector<int> a) {
        // code here
        int dp[k+1][n];
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=k;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=k;i++){
            int ma=INT_MIN;
            for(int j=1;j<n;j++){
                if(dp[i-1][j-1] - a[j-1] > ma)
                ma=dp[i-1][j-1]- a[j-1];
                
                dp[i][j] = max(ma + a[j], dp[i][j-1]);
            }
        }
        
        return dp[k][n-1];
    }
    int maxProfit(vector<int>& prices) {
        return kmaxProfit(2, prices.size(), prices);
    }
};