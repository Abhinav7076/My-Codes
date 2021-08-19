class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool solve(int arr[], int n, int mid, int m){
        int sum = 0;
        int stu = 1;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) //har student ko kam se kam ek book to padhna hi hai
            return false;
            else if(sum+arr[i] > mid){
                stu++;
                sum = arr[i];
                if(stu > m) //agar no of students m se jyada ho jaye to bhi false return karna hai
                return false; 
            }
            else
                sum += arr[i];
        }
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int lb = 0;
        int ub = accumulate(arr, arr+n, 0);
        int ans = 0;
        while(lb<=ub){
            int mid = (lb+ub)/2;
            if(solve(arr,n,mid,m)){ //agar mid tak book padh pa rahe hai to usse kam me bhi check karo
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        return ans;
    }
};