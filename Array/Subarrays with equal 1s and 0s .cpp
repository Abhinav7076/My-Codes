class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long int sum = 0,total=0;
        unordered_map<int, int> u;
        u[0] = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            sum+=-1;
            else
            sum+=1;
            
            if(!u[sum]){
                u[sum]++;
            }
            else{
                total+=u[sum];
                u[sum]++;
            }
        }
        
        return total;
    }
};