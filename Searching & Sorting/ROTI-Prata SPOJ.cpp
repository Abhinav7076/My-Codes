#include <bits/stdc++.h>
using namespace std;

bool solve(int arr[], int p, int n, int mid){
    int time = 0;
    int parota = 0;
    for(int i=0;i<n;i++){
        time = arr[i];  //don't add since every cook starts at same time
        int j = 2;
        while(time <= mid){
            parota++;
            time += arr[i]*j;
            j++;
        }
        if(parota >= p)
            return true;
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int p,n;
        cin>>p>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int lb = 0;
        int ub = 1e8;
        int ans = 0;
        while(lb<=ub){
            int mid = (lb+ub)/2;
            if(solve(arr, p, n, mid)){
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        cout<<ans<<endl;
    }
    
    
	return 0;
}