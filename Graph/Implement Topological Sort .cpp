// topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> in(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            in[x]++; //neighbours ki indegree badhao
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(in[i] == 0)
	        q.push(i);
	    }
	    while(!q.empty()){
	        int t = q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto x:adj[t]){
	            in[x]--;
	            if(in[x]==0)
	            q.push(x);
	        }
	    }
	    return ans;
	}
};

// The Applications of Topological Sort are:
// Finding cycle in a graph.
// Operation System deadlock detection. : Topological sorting is used here to identify a cycle. If the wait-for graph has a cycle, then there is deadlock.
// Dependency resolution. Suppose, A class extends B class. and B also extends A In this case, the java compiler tries to detect circular dependency.
// Course Schedule problem. : There are some courses and they may have some prerequisite courses. One can finish courses in some order.
// Sentence Ordering.
// Critical Path Analysis.
