class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int c=0;
	    for(int i=0;i<n;i++){
	        int l=i+1;
	        int r=n-1;
	        
	        while(l<r){
	            if(arr[l]+arr[i]+arr[r]<sum){
	            c=c+r-l;
	            l++;
	            }
	            else
	            r--;
	        }
	        
	    }
	    
	    return c;
	}
		 

};