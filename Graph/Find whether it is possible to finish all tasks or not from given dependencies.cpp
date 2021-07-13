class Solution {
public:
    
    bool dfs(int i, vector<bool> &visited, vector<bool> &dfsVis, vector<int> adj[]){
        visited[i] = true;
        dfsVis[i] = true;
        for(auto x: adj[i]){
            if(!visited[x]){
                if(dfs(x, visited, dfsVis, adj))
                    return true;
            }
            else{
                if(dfsVis[x])
                    return true;
            }
        }
        dfsVis[i] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]){
        vector<bool> visited(V);
        vector<bool> dfsVis(V);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, visited, dfsVis, adj))
                    return true;
            }
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return !isCyclic(numCourses, adj);
    }
};