//jo bhi bada hoga use wo stack k top ka next greater hoga

vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        unordered_map<long long,long long> u;
        for(long long i=0;i<n;){
            if(s.empty())
            s.push(arr[i++]);
            else if(arr[i] < s.top())
            s.push(arr[i++]);
            else{
                while(!s.empty() and s.top() < arr[i]){
                    long long n = s.top();
                    s.pop();
                    u[n] = arr[i];
                }
                s.push(arr[i++]);
            }
            
        }
        while(!s.empty()){
            long long n = s.top();
            s.pop();
            u[n] = -1;
        }
        u[arr[n-1]] = -1;
        vector<long long> v;
        for(long long i=0;i<n;i++){
            v.push_back(u[arr[i]]);
        }
        return v;
    }