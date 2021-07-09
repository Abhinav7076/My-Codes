class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> q;
        unordered_map<char,int> u;
        for(int i=0;i<s.length();i++)
            u[s[i]]++;
        unordered_map<char,int>::iterator it;
        for(it=u.begin();it!=u.end();it++)
            q.push({it->second, it->first});
        string ans="";
        while(q.size()>1){
            pair<int,char> x = q.top();
            q.pop();
            pair<int,char> y = q.top();
            q.pop();
            
            if(x.first-1>0)
                q.push({x.first-1, x.second});
            if(y.first-1>0)
                q.push({y.first-1, y.second});
            
            ans=ans+x.second+y.second;
        }
        if(q.size()){
            if(q.top().first==1)
                ans+=q.top().second;
            else
                return "";
        }
        return ans;
    }
};