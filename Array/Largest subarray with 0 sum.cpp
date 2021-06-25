int maxLen(int A[], int n)
{
    // Your code here
    int lastsum=0,len=0;
    unordered_map<int, int> u;
    u[0] = -1;
    for(int i=0;i<n;i++){
        lastsum+=A[i];
        auto itr = u.find(lastsum);
        if(itr != u.end()){
            len=max(len,i-u[lastsum]);
            // u[lastsum] = i;
            // cout<<"if "<<lastsum<<" "<<len<<endl;
        }
        
        else{
            // cout<<"!if "<<lastsum<<endl;
        u[lastsum] = i;
        }
        
        
        
    }
    return len;
}
