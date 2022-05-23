#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr, arr+n);
		int lb = 1;
		int ub = 1e9;
		int ans = 0;
		while(lb<=ub){
			int mid = (lb+ub)/2;
			//fixing first cow at first position
			//prev stores position of last cow
			int cows = 1;
			int prev = arr[0];
			for(int i=1;i<n;i++){
				if((arr[i]-prev) >= mid){
					cows++;
					prev = arr[i];
					if(cows == c)
					break;
				}
			}
			if(cows == c){
				ans = mid;
				lb = mid + 1;
			}
			else
				ub = mid - 1;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}