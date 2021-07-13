class Solution
{
    public:
    //Function to find the number of islands.
    void traverse(int x, int y, vector<vector<char>> grid, vector<vector<bool>> &visited){
        queue<pair<int,int> > q;
        q.push({x,y});
        int n =grid.size();
        int col = grid[0].size();
        visited[x][y]=true;
        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            if(f.first-1>=0 and visited[f.first-1][f.second]==0 and grid[f.first-1][f.second]=='1'){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first-1][f.second] = true;
                q.push({f.first-1,f.second});
            }
            if(f.second+1<col and visited[f.first][f.second+1]==0 and grid[f.first][f.second+1]=='1'){
                visited[f.first][f.second+1] = true;
                // cout<<f.first<<" "<<f.second+1<<endl;
                q.push({f.first, f.second+1});
            }
            if(f.first+1<n and visited[f.first+1][f.second]==0 and grid[f.first+1][f.second]=='1'){
                visited[f.first+1][f.second] = true;
                // cout<<f.first+1<<" "<<f.second<<endl;
                q.push({f.first+1,f.second});
            }
            if(f.second-1>=0 and visited[f.first][f.second-1]==0 and grid[f.first][f.second-1]=='1'){
                // cout<<f.first<<" "<<f.second-1<<endl;
                visited[f.first][f.second-1] = true;
                q.push({f.first, f.second-1});
            }
            //northeast
            if(f.first+1<n and f.second+1<col and visited[f.first+1][f.second+1]==0 and grid[f.first+1][f.second+1]=='1'){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first+1][f.second+1] = true;
                q.push({f.first+1,f.second+1});
            }
            //northwest
            if(f.first+1<n and f.second-1>=0 and visited[f.first+1][f.second-1]==0 and grid[f.first+1][f.second-1]=='1'){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first+1][f.second-1] = true;
                q.push({f.first+1,f.second-1});
            }
            //southeast
            if(f.first-1>=0 and f.second+1<col and visited[f.first-1][f.second+1]==0 and grid[f.first-1][f.second+1]=='1'){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first-1][f.second+1] = true;
                q.push({f.first-1,f.second+1});
            }
            //southwest
            if(f.first-1>=0 and f.second-1>=0 and visited[f.first-1][f.second-1]==0 and grid[f.first-1][f.second-1]=='1'){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first-1][f.second-1] = true;
                q.push({f.first-1,f.second-1});
            }
        }
        
        return;

    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' and visited[i][j]==false){
                traverse(i,j,grid,visited);
                c++;
                }
            }
        }
        
        return c;
    }
};