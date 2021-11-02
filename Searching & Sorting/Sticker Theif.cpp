class Solution{
    public:
    // Function to return maximum of sum without adjacent elements
    ll FindMaxSum(ll arr[], ll n)
    {
        if(n==0)
        return -1;
        else if(n==1)
        return arr[0];
        else if(n==2)
        return max(arr[0],arr[1]);
        long long output[n];
        output[0] = arr[0];
        output[1] = max(arr[0], arr[1]);
        
        for(int i=2;i<n;i++)
        output[i] = max(output[i-2]+arr[i], output[i-1]);
        
        return output[n-1];
        
    }
    
};