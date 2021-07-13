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