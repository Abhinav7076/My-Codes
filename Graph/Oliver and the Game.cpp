#include <bits/stdc++.h>
using namespace std;
 
vector<int> inTime;
vector<int> outTime;
int timer = 1;
 
void dfs(int src, int par, vector<int> v[]){
        inTime[src]=timer++;
        for(auto x:v[src]){
            if(x!=par){;
                dfs(x,src,v);
            }
        }
        outTime[src] = timer++;
    }
 
//check uf y is in subtree of x;
bool check(int x, int y){
    if(inTime[y] > inTime[x] and outTime[y] < outTime[x])
    return true;
    return false;
}
 
 
int main() {
	//code
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        vector<int> v[n+1];
        inTime.resize(n+1);
        outTime.resize(n+1);
        for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0,v);
        int q;
        cin>>q;
 
        while(q--){
            vector<bool> visited(n+1,false);
            int choice,x,y;
            cin>>choice>>x>>y;
            if(!check(x,y) and !check(y,x)){
                cout<<"NO\n";
                continue;
            }
            // raja ki taraf
            if(choice == 0){
                if(check(x,y))
                cout<<"YES\n";
                else
                cout<<"NO\n";
            }
            else if(choice == 1){
                if(check(y,x))
                cout<<"YES\n";
                else
                cout<<"NO\n";
            }
        }
    
	
	return 0;
}