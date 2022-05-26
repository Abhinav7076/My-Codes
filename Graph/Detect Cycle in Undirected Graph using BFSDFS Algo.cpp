
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
	        else if(i!=parent) //i==parent means same edge 
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

//if any of the adjacent node has been visited and it is not the previous node then we can say there is a cycle
bool checkByBFS(int s, int V, vector<int> adj[], vector<int> &visited){
        queue<pair<int, int>> q;
        q.push({s, -1});
        visited[s] = true;
        while(!q.empty()){
            int t = q.front().first;
            int prev = q.front().second;
            q.pop();
            for(auto it: adj[t]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it, t});
                }
                else if(it != prev) //it == parent : it is the same edge
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkByBFS(i, V, adj, visited))
                    return true;
            }
        }
        return false;
    }