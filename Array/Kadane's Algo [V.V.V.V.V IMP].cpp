int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int ma=INT_MIN,lastsum=0;
        for(int i=0;i<n;i++){
            if(lastsum>=0){
                lastsum+=arr[i];
            }
            else{
                lastsum=0;
                lastsum+=arr[i];
            }
            ma = max(ma,lastsum);
        }
        return ma;
        
    }