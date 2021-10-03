class Solution {
public:
    // We iterate over each element and mark its corresponding index by setting its sign to minus. If we already marked it as negative, it means its index is a duplicate.
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val = abs(nums[i]);
            if(nums[val]<0)
                return val;
            else
                nums[val] = -nums[val];
        }
        return 0;
    }
};

//slow fast method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};