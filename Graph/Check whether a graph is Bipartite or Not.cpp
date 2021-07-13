class Solution {
public:
int f=0;
    void dfs(int val, int par, int col, vector<int> &visited, vector<int>adj[]){
	    visited[val]=col;
	    //cout<<val<<" ";
	    for(auto node: adj[val]){
	        //cout<<val<<" "<<color[val]<<" "<<node<<" "<<color[node]<<endl;
	        if(visited[node]==-1){
	            dfs(node, val, 3-col, visited, adj);
	        }
	        else if(node!=val and visited[node] == col){
	            f=1;
	            break;
	        }
	    }
	}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V,-1);
	    f=0;
	    for(int i=0;i<V;i++){
	        if(visited[i]==-1)
    	        dfs(i,i,1,visited,adj);
	    }
	    if(f==1)
	        return false;
    	
    	return true;
	}

};