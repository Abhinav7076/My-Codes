#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>> > g;

void Dijkstra(int n, int source){
    // Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n,INT_MAX); 	// 0-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
// 		vector<pair<int,int> >::iterator it;
		for(auto it: g[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 0 ; i<n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
}

int main(){
	int n,m,source;
	cin >> n >> m;
	g.resize(n); 	// 0-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b;
		g[a-1].push_back(make_pair(b-1,1));
		g[b-1].push_back(make_pair(a-1,1));
	}	
	
	source=0;
	Dijkstra(n,0);
	
	return 0;
}

//*******************************************************************************
//without function
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n]; 	// 0-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n,INT_MAX); 	// 0-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 0 ; i<n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}


//*******************************************************************************
//GFG
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> Dijkstra(int n, int source, vector<pair<int,int> > g[]){
    // Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n,INT_MAX); 	// 0-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
// 		vector<pair<int,int> >::iterator it;
		for(auto it: g[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	
	return distTo;
	
}
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<pair<int,int> > g[V];
        vector <int> v;
        v.push_back(2);
        for(int i=0;i<V;i++){
            pair<int,int> p;
            for(auto x:adj[i]){
                vector<int> vec;
                for(auto xx:x){
                    vec.push_back(xx);
                }
                p.first = vec[0];
                p.second = vec[1];
                g[i].push_back(p);
                g[p.first].push_back({i,p.second});
            }

        }
        
        return Dijkstra(V,S,g);
    }
};
