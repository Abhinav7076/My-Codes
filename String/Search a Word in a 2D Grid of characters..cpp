class Solution{
    public:
    int solve(int i, int j, int r, int c, vector<vector<char> > &mat, int idx, int size, string target){
        int found = 0;
        if(i>=0 and j>=0 and i<r and j<c and target[idx] == mat[i][j]){
            char temp = mat[i][j];
            mat[i][j] = '0';
            idx+=1;
            if(idx == size)
            found = 1;
            else{
                found+=solve(i-1,j,r,c,mat,idx,size,target);
                found+=solve(i+1,j,r,c,mat,idx,size,target);
                found+=solve(i,j-1,r,c,mat,idx,size,target);
                found+=solve(i,j+1,r,c,mat,idx,size,target);
            }
            mat[i][j] = temp; //Backtracking
        }
        return  found;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int total = 0, r =mat.size(), c = mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                total += solve(i,j,r,c,mat,0,target.length(),target);
            }
        }
        return total;
        
    }
};