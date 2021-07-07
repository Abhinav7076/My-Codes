class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<int,int> > q;
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int> > dist(n, vector<int>(grid[0].size()));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j] == 0;                    
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            int x=p.first;
            int y=p.second;
            int distance = dist[x][y];
            q.pop();
            
            if(x-1>=0 and grid[x-1][y]==0){
                // cout<<x-1<<" "<<y<<endl;
                dist[x-1][y]=distance+1;
                grid[x-1][y] = 1;
                q.push({x-1,y});
                 
            }
            if(y+1<m and grid[x][y+1]==0){
                // cout<<x<<" "<<y+1<<endl;
                dist[x][y+1]=distance+1;
                grid[x][y+1] = 1;
                q.push({x, y+1});
                 
            }
            if(x+1<n and grid[x+1][y]==0){
                // cout<<x+1<<" "<<y<<endl;
                dist[x+1][y]=distance+1;
                grid[x+1][y] = 1;
                q.push({x+1,y});
                 
            }
            if(y-1>=0 and grid[x][y-1]==0){
                // cout<<x<<" "<<y-1<<endl;
                dist[x][y-1]=distance+1;
                grid[x][y-1] = 1;
                q.push({x, y-1});
                 
            }
            
        }
        
        return dist;
        
        
	}
};