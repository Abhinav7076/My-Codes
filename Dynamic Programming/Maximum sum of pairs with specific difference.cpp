
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here
        sort(arr,arr+n,greater<int>());
        int i=0,sum=0;
        while(i+1<n){
            int diff = abs(arr[i]-arr[i+1]);
            if(diff<k){
                sum=sum+arr[i]+arr[i+1];
                i=i+2;
            }
            else
            i++;
        }
        return sum;
    }
};