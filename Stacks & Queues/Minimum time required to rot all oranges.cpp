class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int, pair<int,int> > > q;
        int n=grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({0, {i,j}});
                else if(grid[i][j]==1)
                fresh++;
            }
        }
        int final = 0;
        while(!q.empty()){
            pair<int, pair<int,int> > f = q.front();
            int samay = f.first;
            int x=f.second.first;
            int y=f.second.second;
            final = samay;
            q.pop();
            
            if(x-1>=0 and grid[x-1][y]==1){
                // cout<<x-1<<" "<<y<<endl;
                grid[x-1][y]=2;
                q.push({samay+1,{x-1,y}});
                fresh--;
            }
            if(y+1<m and grid[x][y+1]==1){
                // cout<<x<<" "<<y+1<<endl;
                grid[x][y+1]=2;
                q.push({samay+1,{x, y+1}});
                fresh--;
            }
            if(x+1<n and grid[x+1][y]==1){
                // cout<<x+1<<" "<<y<<endl;
                grid[x+1][y]=2;
                q.push({samay+1,{x+1,y}});
                fresh--;
            }
            if(y-1>=0 and grid[x][y-1]==1){
                // cout<<x<<" "<<y-1<<endl;
                grid[x][y-1]=2;
                q.push({samay+1,{x, y-1}});
                fresh--;
            }
            
        }
        if(final>0 and fresh==0)
        return final;
        
        return -1;
    }
};