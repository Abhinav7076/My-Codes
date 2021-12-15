The Merge Sort use the Divide-and-Conquer approach to solve the sorting problem. First, it divides the input in half using recursion. After dividing, it sort the halfs and merge them into one sorted output.
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        int n1 = mid-l+1;
        int n2 = r-mid;
        
        int arr1[n1];
        int arr2[n2];
        for(int i=0;i<n1;i++)
            arr1[i] = nums[i+l];
        
        for(int i=0;i<n2;i++)
            arr2[i] = nums[i+mid+1];
        
        int i=0,j=0,k=l;
        
        while(i<n1 and j<n2){
            if(arr1[i]<=arr2[j]){
                nums[k++] = arr1[i++];
            }
            else{
                nums[k++] = arr2[j++];
            }
        }
        while(i<n1){
            nums[k++] = arr1[i++];
        }
        while(j<n2){
            nums[k++] = arr2[j++];
        }
        return;
    }
    void mergesort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};