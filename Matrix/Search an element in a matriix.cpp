//Leetcode
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t_row=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            if(target==matrix[i][matrix[0].size()-1]){
                return true;
            }
            else if(target<matrix[i][matrix[0].size()-1]){
                t_row=i;
                break;
            }
        }
        cout<<t_row;
        if(t_row==INT_MAX)
            return false;
        
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[t_row][i]==target)
                return true;
        }
        return false;
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