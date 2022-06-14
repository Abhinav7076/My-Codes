class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[0]==b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans(n);
        
        sort(people.begin(), people.end(), compare);
        for(int i=0;i<n;i++){
            int value = people[i][0], grh = people[i][1];
            int pos,j; //j is for countig the number of people taller or empty places
            // pos is for storing the position where the element is to be placed
            for(pos=0, j=0;j<=grh;pos++){
                if(!visited[pos] or (visited[pos] and ans[pos][0] >= value))
                    j++;
            }
            pos--;
            ans[pos] = people[i];
            visited[pos] = true;
        }
        return ans;
        
    }
};