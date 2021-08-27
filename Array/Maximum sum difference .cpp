class Solution{
public:
    int maxSum(int n){
        // code here
        if (n == 1)
        return 1;
 
        // Otherwise max sum will
        // be (n*(n-1)/2) - 1 + n/2
        else
            return (n * (n - 1) / 2) - 1 + n / 2;
    }
};