queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    queue<int> ans;
    vector<int> v;
    for(int i=0;i<k;i++){
        v.push_back(q.front());
        q.pop();
    }
    reverse(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
    ans.push(v[i]);
    
    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;
}