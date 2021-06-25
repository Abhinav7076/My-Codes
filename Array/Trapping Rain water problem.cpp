class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        
        int left_big[n]={0};
        int right_big[n]{0};
        left_big[0]=arr[0];
        right_big[n-1]=arr[n-1];
        int drops=0;
        for(int i=1;i<n;i++){
            left_big[i]=max(left_big[i-1], arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            right_big[i]=max(right_big[i+1], arr[i]);
        }
        
        
        for(int i=0;i<n;i++){
            drops=drops+min(right_big[i],left_big[i])-arr[i];
        }
        
        return drops;
        
    }
};