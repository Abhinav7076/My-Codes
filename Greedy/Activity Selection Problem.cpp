class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int> > v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(start[i], end[i]));
        }
        
        std::sort(v.begin(), v.end(),
          [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second;});
        
        int i=0,j=1,c=1;
        while(j<n){
            if(v[j].first > v[i].second){
                i=j;
                c++;
                j++;
            }
            else
            j++;
        }
        return c;
    }
};