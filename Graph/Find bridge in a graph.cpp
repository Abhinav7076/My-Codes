// Bridge. i.e., removing the edge disconnects the graph.
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int val, vector<bool> &visited, vector<int>adj[]){
	    visited[val]=true;
	    //cout<<val<<" ";
	    for(auto node: adj[val]){
	        if(visited[node]==false){
	        dfs(node, visited, adj);
	        }
	    }
	}
	
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V, false);
        int c1=0,c2=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                c1++;
            }
        }
        
        
        fill(visited.begin(), visited.end(), false);
        for(int i=0;i<adj[c].size();i++){
            if(adj[c][i]==d)
                adj[c].erase(adj[c].begin() + i);
        }
        
        for(int i=0;i<adj[d].size();i++){
            if(adj[d][i]==c)
                adj[d].erase(adj[d].begin() + i);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                c2++;
            }
        }
        
        
        //cout<<c1<<" "<<c2<<"\n";
        if(c2-c1>0)
        return 1;
        
        return 0;
        
        
    }
};