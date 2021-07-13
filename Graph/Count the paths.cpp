class Solution {
public:
    void dfs(int val, vector<vector<int> > &v, vector<vector<int> > &result,vector<int> &path, int des){
        path.push_back(val);
        if(val == des)
        result.push_back(path);
        else{
        for(int x:v[val])
               dfs(x,v,result,path,des);
        }
        path.pop_back();
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    int c=0;
	     vector<vector<int> > neighbours(n);
	     for(int i=0;i<edges.size();i++)
    	     neighbours[edges[i][0]].push_back(edges[i][1]);
	    // print(neighbours);
	
	    vector<vector<int> > result;
	    vector<int> path;
	    dfs(s,neighbours,result,path,d);
	    return result.size();
	}
};
