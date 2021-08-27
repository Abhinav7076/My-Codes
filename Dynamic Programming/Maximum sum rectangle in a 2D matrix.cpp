class Solution {
  public:
  int kadane(vector<int> arr, int n){
        // Your code here
        int max_sum=-9999999, last_sum=0;
        for(int i=0;i<n;i++){
            if(last_sum>=0){
                last_sum+=arr[i];
            }
            else if(last_sum<0){
            last_sum=0;
            last_sum+=arr[i];
            }
            max_sum=max(last_sum,max_sum);
        }
        return max_sum;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> grid) {
        // code here
     
        int ma=INT_MIN;
        for(int i=0;i<r;i++){
            vector<int> v(c);
            for(int j=i;j<r;j++){
                for(int k=0;k<c;k++){
                    v[k] = v[k] + grid[j][k];
                }
                int x = kadane(v,c);
                ma=max(ma,x);
            }
        }
        return ma;
    }
};