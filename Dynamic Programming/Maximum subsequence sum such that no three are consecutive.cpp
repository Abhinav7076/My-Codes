class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int output[n];
	    if(n==1)
	    return arr[0];
	    if(n==2)
	    return max(arr[0], arr[1]);
	    
	    output[0] = arr[0];
	    output[1] = max(arr[0], arr[1]);
	    for(int i=2;i<n;i++){
	        output[i] = max(output[i-2] + arr[i], output[i-1]);
	    }
	    return output[n-1];
	    
	}
};