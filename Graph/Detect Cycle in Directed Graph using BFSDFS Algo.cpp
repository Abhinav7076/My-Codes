//dfs to check node if it was called in same visited call
// if the node comes again and if its true then there is a cycle
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

// Kahn's algorithm
// using BFS
// a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering
// is only applicable for DAG

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int> q;
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                indegree[it]++;
        }
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int c = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            c++;
            for(auto it:adj[t]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(c == V) return false; //topological sort successfull hence no cycle
        return true;
    }