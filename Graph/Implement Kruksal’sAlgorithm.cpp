//gfg
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    struct node
    {
        int u,v,wt;
        node(int first, int second, int weight){
            u=first;
            v=second;
            wt=weight;
        }
        
    };    
    
    static bool comp(node n1, node n2){
        return n1.wt < n2.wt;
    }
    
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }
    
    void unionKaro(int u, int v, vector<int> &parent, vector<int> &pad){
        u = findParent(u,parent);
        v = findParent(v,parent);
    
        if(pad[u] < pad[v]){
            parent[u] = v;
        }
        else if(pad[v] < pad[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            pad[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<node> edges;
        for(int i=0;i<V;i++){
            for(auto x: adj[i]){
                vector<int> vec;
                for(auto xx:x){
                    vec.push_back(xx);
                }
                
                edges.push_back(node(i,vec[0],vec[1]));
                edges.push_back(node(vec[0],i,vec[1]));
            }
        }
        
        sort(edges.begin(), edges.end(), comp);
        
        std::vector<int> parent(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        std::vector<int> pad(V,0);
        
        std::vector<int>  mst;
        int cost = 0;
        for(auto x: edges){
            //mst me push karo agar edges k dono vertex diff component me ho
            if(findParent(x.u,parent) != findParent(x.v,parent)){
                cost+=x.wt;
                mst.push_back(x.wt);
                unionKaro(x.u,x.v,parent,pad);
            }
        }
        
        return accumulate(mst.begin(), mst.end(), 0);
        
    }
};

//taking inputs
//**********************************************************************************************
#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++; 
    }
}
int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }
    sort(edges.begin(), edges.end(), comp); 
    
    vector<int> parent(N);
    for(int i = 0;i<N;i++) 
        parent[i] = i; 
    vector<int> rank(N, 0); 
    
    int cost = 0;
    vector<pair<int,int>> mst; 
    for(auto it : edges) {
        if(findPar(it.v, parent) != findPar(it.u, parent)) {
            cost += it.wt; 
            mst.push_back({it.u, it.v}); 
            unionn(it.u, it.v, parent, rank); 
        }
    }
    cout << cost << endl;
    for(auto it : mst) cout << it.first << " - " << it.second << endl; 
    return 0;
}
