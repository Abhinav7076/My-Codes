class Solution
{
    public:
    
     map<pair<int,int>,int>mp;
    pair<int,int> helper(vector<int> adj[],int i,int mini,vector<int> &vis){
        vis[i] = 0;
        for(int j : adj[i]){
            mini = min(mini,mp[{i,j}]);
            return helper(adj,j,mini,vis);
        }
        return {i,mini};
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int> adj[n + 1];
        vector<int> vis(n + 1,1); //incoming wale 0 ho jayenge
        vector<vector<int>> res;
        mp.clear();
        for(int i = 0 ; i < p ; i ++){
            adj[a[i]].push_back(b[i]);
            mp[{a[i],b[i]}] = d[i];
            vis[b[i]] = 0;
        }
        for(int i = 1; i <= n ; i ++){
            if(vis[i] == 1){
            auto it = helper(adj,i,INT_MAX,vis);
            if(i == it.first) continue;
            res.push_back({i,it.first,it.second});
            }
        }
        return res;
    }
};