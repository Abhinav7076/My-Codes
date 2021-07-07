queue<int> rev(queue<int> q)
{
    // add code here.int n=size(Q);
    int n,m;
    n=m=q.size();
    stack<int> s;
    while(n--){
        int t = q.front();
        q.pop();
        s.push(t);
    }
    
    while(m--){
        q.push(s.top());
        s.pop();
    }
    return q;
}