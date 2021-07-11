
class Solution 
{
    public:
	bool dfs(int src,int parent, vector<int>adj[], vector<bool> &visited ){
	    visited[src] = true;
	    for(auto i : adj[src]){
	        if(!visited[i]){
	            if(dfs(i,src,adj,visited))
	            return true;
	        }
	        else if(i!=parent) 
	        return true;
	    }
	    return false;
	}
	
	
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(V,false);
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(dfs(i, -1, adj, visited))
	            return true;
	        }
	    }
	    
	    return false;
	   
	}
};