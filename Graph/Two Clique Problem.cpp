// A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other. Given a Graph, find if it can be divided into two Cliques.

 // A graph can be divided in two cliques if its complement graph is Bipartitite.
// If complement is Bipartite, then graph can be divided into two sets U and V such that there is no edge 
// connecting to vertices of same set. This means in original graph, these sets U and V are completely connected. Hence original graph could be divided in two Cliques.

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
	        else if(node!=val and visited[node] == col){ //agar same edge nahi hai and adjacent node ka color bhi same hai then return 1
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