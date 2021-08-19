#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int n,c;
	cin>>n>>c;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr, arr+n);
	int lb = 0;
	int ub = arr[n-1];
	int ans = 0;
	while(lb<=ub){
		int mid = (lb+ub)/2;
		//fixing first cow at first position
		int trees = 1;
		int prev = arr[0];
		
		int sum = max(0, arr[0] - mid);
		for(int i=1;i<n;i++){
			if((arr[i]-mid) >= 0){
				trees++;
				sum += arr[i] - mid;
				prev = arr[i];
				if(sum >= c)
				break;
			}
		}
		if(sum >= c){
		    ans = mid;
			lb = mid + 1;
		}
		else
			ub = mid - 1;
	}
	cout<<ans<<endl;

	
	return 0;
}