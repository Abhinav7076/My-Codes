class Solution {
public:
	struct node{
      int u,v,wt;
      node(int f, int s, int weight){
          u=f;
          v=s;
          wt = weight;
      }
    };
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   // for(int k=0;k<n;k++){
	        
	    int inf=100000;
	    vector<int> dist(n,inf);
	    dist[0] = 0;
	    
	    
	    for(int i=1;i<=n-1;i++){
	        for(auto x:edges){
	            if(dist[x[0]] + x[2] < dist[x[1]])
	                dist[x[1]] = dist[x[0]] + x[2];
	        }
	    }
	    int f=0;
      for(auto x:edges){
          if(dist[x[0]] + x[2] < dist[x[1]]){
              dist[x[1]] = dist[x[0]] + x[2];
              f=1;
              break;
          }
      }
  
	
    return f;

	//}
	return 0;
	}
};