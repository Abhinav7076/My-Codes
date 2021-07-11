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
    
    void revdfs(int val, vector<int> adj[], vector<bool> &visited){
    // cout<<val;
    visited[val] = true;
    for(auto x:adj[val]){
        if(visited[x]==false)
            revdfs(x,adj,visited);
        }
    }

    int kosaraju(int N, vector<int> adj[])
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
	
	
	int c=0;
	while(!st.empty()){
	    int t = st.top();
	    st.pop();
	    if(!visited[t]){
	        //cout<<"SCC : ";
	        revdfs(t, v2, visited);
	        c++;
	        //cout<<endl;
	    }
	}
	
	return c;
	
    }
};