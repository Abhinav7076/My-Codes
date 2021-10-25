/*
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250. 
*/

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