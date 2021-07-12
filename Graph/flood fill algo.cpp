class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        queue<pair<int,int> > q;
        q.push({sr,sc});
        int n =image.size();
        int col = image[0].size();
        vector<vector<bool> > visited(n, vector<bool>(image[0].size()));
        visited[sr][sc]=true;
        int c=image[sr][sc];
        while(!q.empty()){
            pair<int,int> f = q.front();
            image[f.first][f.second] = newColor;
            q.pop();
            if(f.first-1>=0 and visited[f.first-1][f.second]==0 and image[f.first-1][f.second]==c){
                // cout<<f.first-1<<" "<<f.second<<endl;
                visited[f.first-1][f.second] = true;
                q.push({f.first-1,f.second});
            }
            if(f.second+1<col and visited[f.first][f.second+1]==0 and image[f.first][f.second+1]==c){
                visited[f.first][f.second+1] = true;
                // cout<<f.first<<" "<<f.second+1<<endl;
                q.push({f.first, f.second+1});
            }
            if(f.first+1<n and visited[f.first+1][f.second]==0 and image[f.first+1][f.second]==c){
                visited[f.first+1][f.second] = true;
                // cout<<f.first+1<<" "<<f.second<<endl;
                q.push({f.first+1,f.second});
            }
            if(f.second-1>=0 and visited[f.first][f.second-1]==0 and image[f.first][f.second-1]==c){
                // cout<<f.first<<" "<<f.second-1<<endl;
                visited[f.first][f.second-1] = true;
                q.push({f.first, f.second-1});
            }
        }
        
        return image;
    }
};