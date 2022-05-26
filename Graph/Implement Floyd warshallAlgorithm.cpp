// The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. 
// The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph
// Lastly Floyd Warshall works for negative edge but no negative cycle, whereas Dijkstra's algorithm don't work for negative edges.
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n =matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = INT_MAX;
	        }
	    }
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][k] != INT_MAX and matrix[k][j]!=INT_MAX and matrix[i][j] > matrix[i][k] + matrix[k][j])
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	            }
	        }
	    }
	    // D0[2,3] = D0[2,1] + D0[1,3]
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j] == INT_MAX)
	                matrix[i][j] = -1;
	        }
	    }
	    return;
	}
};