class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    if(n==m)
    return (a[n-1]-a[0]);
    long long mi=INT_MAX;
    for(int i=0;i<=n-m;i++){
        mi = min(mi, a[m+i-1]-a[i]);
    }
    
    return mi;
    }   
};