class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        q.push(a[i]);
        
        for(int i=0;i<m;i++)
        q.push(b[i]);
        
        vector<int> v;
        while(!q.empty()){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};

//method 2
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> v;
        for(int i=0;i<n;i++)
        v.push_back(a[i]);
        
        for(int i=0;i<m;i++)
        v.push_back(b[i]);
        
        sort(v.begin(), v.end(), greater<int>());
        
        return v;
    }
};