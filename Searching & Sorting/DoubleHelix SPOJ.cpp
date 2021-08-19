#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1){
        int n;
        cin>>n;
        if(n == 0)
            break;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int m;
        cin>>m;
        int arr2[m];
        for(int i=0;i<m;i++)
            cin>>arr2[i];
        
        int i=0,j=0,s1=0,s2=0,ans=0;
        while(i<n and j<m){
            if(arr[i] < arr2[j])
                s1 += arr[i++];
            else if(arr2[j] < arr[i])
                s2 += arr2[j++];
            else{
                ans += max(s1, s2) + arr[i];
                s1=0;
                s2=0;
                i++;
                j++;
            }
        }
        while(i<n)
            s1 += arr[i++];
        
        while(j<m)
            s2 += arr2[j++];
        
        ans += max(s1,s2);
        cout<<ans<<endl;
    }
    
    
	return 0;
}