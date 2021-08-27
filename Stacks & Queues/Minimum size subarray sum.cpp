class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target > accumulate(nums.begin(), nums.end(), 0))
            return 0;
        queue<int> q;
        int n = nums.size(), sum=0, mi=INT_MAX;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum < target){
                q.push(nums[i]);
            }
            else{
                q.push(nums[i]);
                while(!q.empty() and sum >= target){
                    if(q.size()<mi)
                        mi = q.size();
                    sum = sum - q.front();
                    q.pop();
                }
                
            }
        }
        
        return mi;
        
    }
};