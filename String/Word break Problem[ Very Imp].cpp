unordered_map<string,int> dp;

int solve(string s, vector<string> &B){
    int l = s.length();
    if(l==0)
    return 1;
    
    if(dp[s]!=0)
    return dp[s];
    
    for(int i=1;i<=l;i++){
        int f=0;
        string str=s.substr(0,i);
        for(int j=0;j<B.size();j++){
            if(str.compare(B[j])==0){
                f=1;
                break;
            }
        }
        if(f==1 and solve(s.substr(i,l-i),B)==1)
        return dp[s] = 1;
    }
    return dp[s]=-1;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    unordered_map<string,int> u;
    int x=solve(A,B);
    if(x==1)
    return 1;
    return 0;
    
}