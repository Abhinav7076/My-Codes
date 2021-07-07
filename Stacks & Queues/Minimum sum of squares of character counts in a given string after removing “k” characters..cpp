class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> u;
        for(int i=0;i<s.length();i++)
        u[s[i]]++;
        
        unordered_map<char,int>::iterator it;
        priority_queue<int> q;
        for(it=u.begin();it!=u.end();it++){
            q.push(it->second);
        }
        
        while(k!=0){
            int t = q.top();
            q.pop();
            q.push(--t);
            k--;
        }
        
        int sum=0;
        while(!q.empty()){
            sum+=pow(q.top(), 2);
            q.pop();
        }
        
        return sum;
        
    }
};