class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0,p=1;
    	while(i<n){
    	    if(arr[i]<=dep[j])
    	    p++;
    	    else
    	    j++;
    	    
    	    i++;
    	}
    	return p;
    }
};