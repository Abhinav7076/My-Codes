#include <iostream>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int dp[n];
	    for(int k=0;k<n;k++){
	    int minSum=arr[k], lastsum=arr[k];
	    for(int i=k+1;i<n;i++){
	        if(lastsum<=0){
	            lastsum=lastsum+arr[i];
	        }
	        else{
	            lastsum=0;
	            lastsum=lastsum+arr[i];
	        }
	        minSum=min(minSum, lastsum);
	    }
	    dp[k] = minSum;
	    }
	    for(int i=0;i<n;i++)
	    cout<<dp[i]<<" ";
	    cout<<"\n";
	}
	
	return 0;
}