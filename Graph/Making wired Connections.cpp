//count the connected components
class Solution {
public:
    void dfs(int val, vector<int> v[], vector<bool> &visited){
        visited[val]=true;
        for(auto x:v[val]){
            if(!visited[x])
                dfs(x,v,visited);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        vector<int> v[n];
        for(int i=0;i<connections.size();i++){
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        int c=0;
        vector<bool> visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(i, v, visited);
            }
        }
        
        return c-1;
    }
};