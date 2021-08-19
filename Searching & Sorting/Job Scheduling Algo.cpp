class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int> > v(n);
        for(int i=0;i<n;i++){
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end(), compare);
        int dp[n];
        dp[0] = v[0][2];
        for(int i=1;i<n;i++){ //simple strategy check profit by including and excluding that interval and choose which ever is maximum
            int inc = v[i][2]; //include profit
            int last = -1;
            int lb = 0;
            int ub = i - 1;
            while(lb<=ub){
                int mid = (ub+lb)/2;
                if(v[mid][1] <= v[i][0]){ //check for non overlapping interval
                    last = mid;
                    lb = mid + 1;
                }
                else
                    ub = mid - 1;
            }
            if(last != -1)
                inc += dp[last];
            int exc = dp[i-1];
            dp[i] = max(inc, exc);
        }
        return dp[n-1];
    }
};