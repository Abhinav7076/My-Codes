class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int left=0,sum=0,mi=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>x){
                mi=min(mi,i+1-left);
                sum-=arr[left]; //popping from left to find smallest subarray
                left++;
            }
        }
        // cout<<mi<<endl;
        return (mi != INT_MAX) ? mi : 0;
    }
};