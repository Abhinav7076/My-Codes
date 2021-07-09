class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        vector<int> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
            v.push_back(matrix[i][j]);
        }
        sort(v.begin(),v.end());
        
        if(v.size()%2==1)
	    return v[v.size()/2];
	    else
	    return (v[v.size()/2]+v[v.size()/2 -1 ])/2;
    }
};