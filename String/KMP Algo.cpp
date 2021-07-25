class Solution{
public:		

		
	int lps(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    int pie[n];
	    pie[0] = 0;
	    int i=0, j=1;
	    while(j<n){
	        if(s[i] == s[j]){
	            pie[j] = i+1;
	            i++;
	            j++;
	        }
	        else{
	            if(i==0){
	                pie[j] = 0;
	                j++;
	            }
	            else{
	                i = pie[i-1];
	            }
	        }
	    }
	    return pie[n-1];
	    //return string(s.end() - pie[n-1], s.end());
	}
};