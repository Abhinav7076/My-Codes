class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    int j=0;
	    unordered_map<char,int> u;
	    for(int i=0;i<S.length();i++){
	        if(!u[S[i]]){
	            S[j++] = S[i];
	            u[S[i]]++;
	        }
	    }
	    S[j] = S[S.length()-1];
	    
	    return string(S.begin(), S.begin()+j);
	}
};

// Function to remove duplicate elements
// This function returns new size of modified
// array.
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;
 
    // To store index of next unique element
    int j = 0;
 
    // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];
 
    arr[j++] = arr[n-1];
 
    return j;
}