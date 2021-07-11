class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(int node, vector<int> &visited, vector<int>&ans, vector<int> adj[]){
	    ans.push_back(node);
	    visited[node] = 1;
	    for(auto x: adj[node]){
	        if(!visited[x])
	        dfs(x,visited,ans,adj);
	    }
	    return;
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> visited(V,0);
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	            dfs(i, visited, ans, adj);
	    }
	    return ans;
	}
};