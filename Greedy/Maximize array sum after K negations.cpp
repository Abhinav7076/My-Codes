class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        // Your code goes here
        sort(arr,arr+n);
        int i;
        for(i=0;i<k;i++){
            if(i==n-1)
            break;
            if(arr[i]<0)
            arr[i]=-arr[i];
            else
            break;
        }
        if((k-i)%2==1)
        arr[i] = -arr[i];
        
        return accumulate(arr,arr+n,0);
        
    }
};
