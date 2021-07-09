class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        int up=0,bottom=r-1,left=0,right=c-1;
        vector<int> ans;
        while(up<=bottom and left<=right){
            for(int j=left;j<=right and up<=bottom;j++){
            ans.push_back(matrix[up][j]);
            //cout<<matrix[up][j]<<" ";
            }
            
            
            up++;
            
            
            for(int j=up;j<=bottom and left<=right;j++){
            ans.push_back(matrix[j][right]);
            //cout<<matrix[j][right]<<" ";
            }
            
            right--;
            
            for(int i=right;i>=left and up<=bottom;i--){
            ans.push_back(matrix[bottom][i]);
            //cout<<matrix[bottom][i]<<" ";
            }
            
            bottom--;
            
            for(int i=bottom;i>=up and left<=right;i--){
            ans.push_back(matrix[i][left]);
            //cout<<matrix[i][left]<<" ";
            }
            
            left++;
        }
        
        return ans;
    }
};