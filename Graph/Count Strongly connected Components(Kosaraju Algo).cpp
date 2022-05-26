// kosaraju algorithm helps us to find all strongly connected components
// scc: if you start from any node you can reach any node
// steps:-
// 1.sort all algorithms in order of finishing time(use topological sort)
// 2. transpose the graph
// 3. do the dfs of new graph according to finishing time
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
	
	vector<bool> visited(N);
	//v.resize(N+1);
	stack<int> st;
	for(int i=0;i<N;i++){
	    if(!visited[i]){
	        dfs(i,adj,visited,st);
	    }
	   // cout<<endl;
	}

	vector<int> transpose[N];

	for(int i=0;i<N;i++){
	    visited[i] = false;
	    for(auto it:adj[i])
	    	transpose[it].push_back(i);
	}
	
	
	int c=0;
	while(!st.empty()){
	    int t = st.top();
	    st.pop();
	    if(!visited[t]){
	        //cout<<"SCC : ";
	        revdfs(t, transpose, visited);
	        c++;
	        //cout<<endl;
	    }
	}
	
	return c;
	
    }
};

// time complexity = O(N) + O(N+E) + O(N+E)