class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        
    }
};

//method 2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i;
                break;
            }
         }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int prev=idx;
            for(int i=idx+1;i<nums.size();i++){
                if(nums[i]>nums[idx-1] and nums[i]<=nums[prev]){
                    prev=i;
                }
            }
            swap(nums[idx-1],nums[prev]);
            reverse(nums.begin()+idx,nums.end());
        }
        
    }
};