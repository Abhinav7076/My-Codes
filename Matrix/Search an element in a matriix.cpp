//Leetcode
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        if(target<matrix[0][0] and target>matrix[r-1][c-1])
            return false;
        
        int t_row=-1;
        for(int i=0;i<r;i++){
            if(matrix[i][c-1] == target)
                return true;
            else if(matrix[i][c-1] > target){
                t_row=i;
                break;
            }
        }
        if(t_row == -1)
            return false;
        
        return binary_search(matrix[t_row].begin(), matrix[t_row].end(), target);
    }
};

//GFG
class Solution{
public: 
    int matSearch (vector <vector <int>> &mat, int N, int M, int X)
    {
        // your code here
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(X>=mat[i][0] and X<=mat[i][M-1] and binary_search(mat[i].begin(), mat[i].end(),X))
                return 1;
            }
        }
        return 0;
    }
};