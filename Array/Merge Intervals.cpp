
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> result;
        vector<vector<int>>::iterator it;
        it=intervals.begin();
        int i=0,j=1;
        for(i=0;i<intervals.size()-1 && j<intervals.size();){
            
            
            if(intervals[i][1]>=intervals[j][0]){
                intervals[i][1]=max(intervals[j][1],intervals[i][1]);
                
                j++;
            }
            else{
                result.push_back(intervals[i]);
                i=j;
                j++;
                
            }
            
        }
        result.push_back(intervals[i]);
        return result; 
        
    }
};