#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, l;
	    cin>>n>>l;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    unordered_map<int, int> u;
	    for(int i=0;i<n;i++){
	    u[arr[i]] = 1;
	    }
	    int f=0;
	    for(int i=0;i<n;i++){
	        if(u[arr[i] + l] == 1){
	        cout<<1<<endl;
	        f=1;
	        break;
	        }
	        else
	        u[arr[i]]=1;
	    }
	    if(f==0)
	    cout<<-1<<endl;
	    
	}
	return 0;
}