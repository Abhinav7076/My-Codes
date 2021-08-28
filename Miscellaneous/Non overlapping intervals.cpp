class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int c=0,start=intervals[0][0],end=intervals[0][1],n=intervals.size();
        for(int i=1;i<n;i++){
            //overlapping is subset
            if(intervals[i][0]>=start and intervals[i][1]<=end){
                start = intervals[i][0];
                end = intervals[i][1];
                c++;
            }
            //overlapping but not subset
            else if(intervals[i][0]<end){
                c++;
            }
            //non overlapping
            else if(intervals[i][0]>=end){
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // cout<<start<<" "<<end<<"\n";
        }
        return c;
    }
};