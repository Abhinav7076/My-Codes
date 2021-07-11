class Solution 
{
    public:
    //Function to find out minimum s+'U' Knight needs to reach target position.
	
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];

        int arr[1001][1001];
        memset(arr, 0 , sizeof(arr));
        
        queue<pair<int,int> > q;
        q.push({x1-1,y1-1});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i-2>=0 and j+1<n and arr[i-2][j+1]==0){
                arr[i-2][j+1]=arr[i][j]+1;
                q.push({i-2, j+1});
            }
            if(i-1>=0 and j+2<n and arr[i-1][j+2]==0){
                arr[i-1][j+2]=arr[i][j]+1;
                q.push({i-1, j+2});
            }
            if(i+1<n and j+2<n and arr[i+1][j+2]==0){
                arr[i+1][j+2]=arr[i][j]+1;
                q.push({i+1, j+2});
            }
            if(i+2<n and j+1<n and arr[i+2][j+1]==0){
                arr[i+2][j+1]=arr[i][j]+1;
                q.push({i+2, j+1});
            }
            if(i-2>=0 and j-1>=0 and arr[i-2][j-1]==0){
                arr[i-2][j-1]=arr[i][j]+1;
                q.push({i-2, j-1});
            }
            if(i-1>=0 and j-2>=0 and arr[i-1][j-2]==0){
                arr[i-1][j-2]=arr[i][j]+1;
                q.push({i-1, j-2});
            }
            if(i+1<n and j-2>=0 and arr[i+1][j-2]==0){
                arr[i+1][j-2]=arr[i][j]+1;
                q.push({i+1, j-2});
            }
            if(i+2<n and j-1>=0 and arr[i+2][j-1]==0){
                arr[i+2][j-1]=arr[i][j]+1;
                q.push({i+2, j-1});
            }
            
        }
        return arr[x2-1][y2-1];

	}
};
