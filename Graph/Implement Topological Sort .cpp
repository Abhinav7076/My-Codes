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
	            in[x]++;
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
