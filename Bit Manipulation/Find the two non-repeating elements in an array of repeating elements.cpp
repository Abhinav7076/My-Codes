class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++){
            u[nums[i]]++;
        }
        vector<int> v;
        unordered_map<int,int>::iterator it;
        for(it=u.begin();it!=u.end();it++){
            if(it->second == 1)
            v.push_back(it->first);
        }
        if(v[0]>v[1])
        swap(v[0],v[1]);
        return v;
    }
};