#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int M, N;
    bool check(vector<vector<char>>&grid, string& word, int i, int j, int di, int dj) {
        int K = word.size();
        int ei = i + di * K, ej = j + dj * K;
        if (ei < -1 || ej < -1 || ei > M || ej > N) return false;
        for (int k = 0; k < K; k++) 
            if (word[k] != grid[i+di*k][j+dj*k])
                return false;
        return true;
    }
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        M = grid.size(); N = grid[0].size();
        vector<vector<int>> R;
        vector<pair<int, int>> D =
            {{1,0},{0,1},{-1,0},{0,-1}
            ,{1,1},{-1,1},{1,-1},{-1,-1}};
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < 8; k++) {
                    auto di = D[k].first;
                    auto dj = D[k].second;
            	    if (check(grid, word, i, j, di, dj)) {
            	        R.push_back({i,j});
            	        break;
            	    }
                }
        return R;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends

// Time complexity: O(R*C*8*len(str)). 