
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int node, vector<int> &visited, vector<int> &dfsVis, vector<int> adj[]){
	    visited[node] = 1;
	    dfsVis[node] = 1;
	    for(auto x: adj[node]){
	        if(!visited[x]){
	            if(dfs(x,visited,dfsVis,adj))
	            return true;
	        }
	        else{
	            if(dfsVis[x])
	            return true;
	        }
	    }
	    dfsVis[node] = 0;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> visited(V,0);
	    vector<int> dfsVis(V,0);
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(dfs(i, visited, dfsVis, adj))
	            return true;
	        }
	    }
	    return false;
	}
};