class Solution {
public:

int  tsp(int mask,int pos, int VISITED_ALL, int n, vector<vector<int>>cost, vector<vector<int>> &dp){
	
	if(mask==VISITED_ALL){
		return cost[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){
		//to check if node is not visited
		if((mask&(1<<city))==0){

			int newAns = cost[pos][city] + tsp( mask|(1<<city), city, VISITED_ALL, n, cost, dp);
			ans = min(ans, newAns);
		}

	}
	
	return dp[mask][pos] = ans;
} 

int total_cost(vector<vector<int>>cost){
    // Code here
    int n = cost.size();
    int VISITED_ALL = (1<<n) -1;
    vector<vector<int>> dp((1<<n), vector<int>(n, -1));
    
    
    return tsp(1, 0, VISITED_ALL, cost.size(), cost, dp);
}
};