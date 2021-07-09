class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int X) {
        int N = mat.size();
        int M = mat[0].size();
        
        if(X<mat[0][0] or X>mat[N-1][M-1])
            return false;
        
        int r=0,c=M-1;
        while(r<N and c>=0){
            if(mat[r][c] == X)
                return true;
            else if(X > mat[r][c])
                r++;
            else if(X < mat[r][c])
                c--;
        }
        return false;
    }
};