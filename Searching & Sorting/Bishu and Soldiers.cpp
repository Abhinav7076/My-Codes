#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        if(k>=arr[n-1])
            cout<<n<<" "<<accumulate(arr, arr+n, 0)<<endl;
        else{
            int idx = upper_bound(arr, arr+n, k) - arr;
            cout<<idx<<" "<<accumulate(arr, arr + idx, 0)<<endl;
        }

    }

    return 0;
}