class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    int least=INT_MAX,l=0;
	    for(int i=n-1;i>=0;i--){
	        least=min(least,arr[i]);
	        if(least!=arr[i]){
	            l=i;
	        }
	    }
	    int maximum=INT_MIN,r=0;
	    for(int i=0;i<n;i++){
	        maximum=max(arr[i],maximum);
	        if(maximum!=arr[i]){
	            r=i;
	        }
	    }
	    return {l,r};
	}
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int least=INT_MAX,l=0;
	    for(int i=n-1;i>=0;i--){
	        least=min(least,arr[i]);
	        if(least!=arr[i]){
	            l=i;
	        }
	    }
	    int maximum=INT_MIN,r=0;
	    for(int i=0;i<n;i++){
	        maximum=max(arr[i],maximum);
	        if(maximum!=arr[i]){
	            r=i;
	        }
	    }
        if(r==0 and l==0)
            return 0;
	    return r-l+1;
    }
};