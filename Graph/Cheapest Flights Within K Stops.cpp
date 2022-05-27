class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        int ans=INT_MAX;
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops=0;
        while(stops<=k && !q.empty()) {
            int sz=q.size();
            while(sz--) {
                int cnode=q.front().first;
                int cdist=q.front().second;
                q.pop();
                if(cdist>dist[cnode]) continue;
                dist[cnode]=cdist;
                for(auto e : graph[cnode]) {
                    if(e.first==dst) ans=min(ans, e.second+cdist);
                    q.push({e.first, e.second+cdist});
                }
            }
            stops++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
// Time complexity = O(V+E)
// 2 and 3 don't pass all tc
//method 2
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> edges(n);
        for(vector<int>& flight : flights){
            //src -> (dst1, price1), (dst2, price2), ...
            edges[flight[0]].emplace_back(flight[1], flight[2]);
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> cur;
        int curCost, curSrc, curK;
        
        //(cost from source, current node, max distance to destination allowed)
        pq.push({0, src, K+1});
        
        //visit nodes in increasing price order
        while(!pq.empty()){
            cur = pq.top(); pq.pop();
            curCost = cur[0]; curSrc = cur[1]; curK = cur[2];
            if(curSrc == dst){
                return curCost;
            }
            if(curK > 0){
                for(pair<int, int>& nei : edges[curSrc]){
                    pq.push({curCost+nei.second, nei.first, curK-1});
                }
            }
        }
        
        return -1;
    }
};

//method 3
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<pair<int,int> > > g(n);
        for(auto x:flights){
            g[x[0]].push_back({x[1],x[2]});
        }
        //cost city stops
        queue<tuple<int,int,int> > q;
        q.push(make_tuple(0,src,0));
        int mi = INT_MAX;
        while(!q.empty()){
            auto [cost, u, stops] = q.front();
            q.pop();
            if(stops>k)
                continue;
            if(cost>mi)
                continue;
            for(auto x:g[u]){
                auto [v,w] = x;
                if(v==dst)
                    mi = min(mi,cost+w);
                q.push(make_tuple(cost+w, v, stops+1));
                
            }
        }
        if(mi==INT_MAX)
            return -1;
        return mi;
    }
};