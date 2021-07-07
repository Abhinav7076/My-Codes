class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        //sort according to start time
        sort(events.begin(), events.end());
        priority_queue<int,vector<int>,greater<int>> q;
        int i=0,n=events.size(),c=0;
        for(int d=1;d<=100000;d++){
            //agar event ka end time d se hi chota hai to use pop karna padega
            while(q.size() and q.top() < d){
                q.pop();
            }
            //d date pe start hone walo ko q me insert karna hai
            while(i<n and events[i][0] == d){
                q.push(events[i][1]);
                i++;
            }
            if(q.size()){
                c++;
                q.pop();
            }
        }
        return c;
    }
};