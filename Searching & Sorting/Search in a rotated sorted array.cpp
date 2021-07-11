int binarysearch(vector<int>& nums,int l, int r, int target){
        while(l<=r){
            int mid=(l+r)/2;
            cout<<nums[mid]<<" ";
            if(target==nums[mid])
                return mid+1;
            
            else if(target<nums[mid])
                return binarysearch(nums, l, mid-1, target);
            
            else
                return binarysearch(nums, mid+1, r, target);
        }
    
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                return i;
        }
        //return binarysearch(nums,0, nums.size()-1,target);
        return -1;
    }
};