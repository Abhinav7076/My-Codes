class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> g[])
	{
	    // Code here
	    vector<int> v;
	    queue<int> q;
	    vector<int> visited(V,0);
	    
	    q.push(0);
	    visited[0]=1;
	    while(!q.empty()){
	        int td=q.front();
	        v.push_back(td);
	        q.pop();
	        for(auto x: g[td]){
	            if(visited[x]==0){
	                visited[x]=1;
	                q.push(x);
	            }
	        }
	    }
	    return v;
	}
};