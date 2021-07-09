//method 1 : using priority q
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto i:nums){
            q.push(i);
            if(q.size()>k)
                q.pop(); // chote walo ko pop karo
        }
        return q.top();
    }
};

//method 2 : using randomized quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        int index = 0;
        int left = 0; 
        int right = nums.size()-1;
        while(true){
            index = partition(nums, left, right);
            if(index==k) break;
            else if(index>k){
                right = index-1;
            }
            else{
                left = index+1;
            }
        }
        return nums[index];
    }
    
    int partition(vector<int> &nums, int low, int high){
        int pivot_pos = rand() % (high-low+1)+low;  // random select pivot position(ensure the selected index between low and high index)
        int pivot = nums[pivot_pos];
        swap(nums[pivot_pos],nums[high]);
        //----below is classical quick sort process----
        int l = low-1;
        for(int i = low; i<high; i++){
            if(nums[i]<pivot){
                l++;
                swap(nums[l],nums[i]);
            }
        }
        swap(nums[l+1],nums[high]);
        return l+1;
    }
};