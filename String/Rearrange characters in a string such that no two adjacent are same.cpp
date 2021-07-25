#include <bits/stdc++.h>
using namespace std;

int findFrequency(string s){
    unordered_map<char,int> u;
    for(int i=0;i<s.length();i++){
        u[s[i]]++;
    }
    unordered_map<char,int>::iterator it;
    int ma=0;
    for(it=u.begin();it!=u.end();it++){
        ma=max(ma,it->second);
    }
    return ma;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ma = findFrequency(s);
	    int n = s.length();
	    if(ma<=n-ma+1)
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}