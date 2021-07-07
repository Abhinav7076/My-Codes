vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    queue<int> q;
    for(int i=0;i<k;i++){
        if(a[i]<0)
        q.push(a[i]);
    }
    vector<long long> v;
    if(!q.empty())
    v.push_back(q.front());
    else
    v.push_back(0);
    
    for(int i=1;i<=n-k;i++){
        int leaving = a[i-1];
        int arriving = a[i+k-1];
        
        // cout<<leaving<<" "<<i<<" "<<arriving<<" "<<q.front()<<endl;
        
        if(leaving == q.front())
        q.pop();
        
        if(arriving<0)
        q.push(arriving);
        
        if(!q.empty())
        v.push_back(q.front());
        else
        v.push_back(0);
        
        
    }
    return v;
    
     
 }