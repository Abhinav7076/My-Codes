#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int val, vector<int> adj[], vector<bool> &visited, stack<int> &st){
    // cout<<val;
    visited[val] = true;
    for(auto x:adj[val]){
        if(visited[x]==false)
            dfs(x,adj,visited,st);
        }
        st.push(val);
    }
    
    void revdfs(int val, vector<int> adj[], vector<bool> &visited, vector<int> &ans){
    // cout<<val;
    ans.push_back(val);
    visited[val] = true;
    for(auto x:adj[val]){
        if(visited[x]==false)
            revdfs(x,adj,visited,ans);
        }
    }

    void kosaraju(int N, vector<int> adj[])
    {
        //code here
    //vector<vector<int> > v(N);
	vector<int> v2[N];

	vector<bool> visited(N);
	//v.resize(N+1);
	stack<int> st;
	for(int i=0;i<N;i++){
	    if(!visited[i]){
	        dfs(i,adj,visited,st);
	    }
	   // cout<<endl;
	}
	
	for(int i=0;i<N;i++){
	    visited[i] = false;
	    for(int j=0;j<adj[i].size();j++){
	        v2[adj[i][j]].push_back(i);
	    }
	}
	
	
	vector<int> indicator(N,0);
	while(!st.empty()){
	    int t = st.top();
	    st.pop();
	    if(!visited[t]){
            vector<int> ans;
	        
	        revdfs(t, v2, visited, ans);
            // cout<<"SCC : "<<ans.size();
            if(ans.size()>2){
                for(int i=0;i<ans.size();i++)
                    indicator[ans[i]] = 1;
            }
                // cout<<endl;
	    }
	}
	
    for(int i=0;i<N;i++) 
        cout<<indicator[i]<<" ";
    
	return;
	
    }
};

int main() {

	// Write your code here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    Solution ob;
    ob.kosaraju(V,adj);
}



















