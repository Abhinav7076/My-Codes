int doUnion(int a[], int n, int b[], int m)  {
    //code here
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    
    for(int i=0;i<m;i++)
        s.insert(b[i]);
    
    set<int>::iterator it;
    return s.size();
    
    
}