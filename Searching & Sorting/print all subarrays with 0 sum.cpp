class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll total = 0, sum = 0;
        unordered_map<ll,ll> u;
        u[0] = 1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(!u[sum]){
                u[sum]++;
            }
            else{
                total = total + u[sum];
                u[sum]++;
            }
        }
        return total;
    }
};