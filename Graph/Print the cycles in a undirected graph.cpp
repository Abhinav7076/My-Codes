class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
// 	unordered_map<int,bool> isInCycle;
	bool dfs(int src,int parent, int original, vector<int>adj[], vector<bool> &visited, vector<bool> &isInCycle){
	    visited[src] = true;
	    for(auto i : adj[src]){
	        if(!visited[i]){
	            if(dfs(i,src,original,adj,visited,isInCycle)){
	            cout<<i<<" ";
	            isInCycle[i] = true;
	            return true;
	            }
	        }
	        else if(i!=parent and i==original){ 
	        cout<<original<<" ";
	        isInCycle[original] = true;
	        return true;
	        }
	    }
	    return false;
	}
	
	
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(V,false);
	    vector<bool> isInCycle(V,false);
	    
	    int c=0;
	    
	    for(int i=0;i<V;i++){
	        fill(visited.begin(), visited.end(), false);
	            if(!isInCycle[i]){
	            if(dfs(i, -1, i, adj, visited, isInCycle)){
	            c++;
	            cout<<endl;
	            }
	            }
	           // cout<<"After "<<i<<" th iteration"<<endl;
	           // for(int j=0;j<V;j++){
	           //     cout<<j<<" "<<isInCycle[j]<<endl;
	           // }
	        }
	    
	    
	    return false;
	   
	}
};