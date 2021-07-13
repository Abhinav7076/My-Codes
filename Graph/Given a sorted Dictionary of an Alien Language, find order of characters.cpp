class Solution{
    public:
    
    pair<char,char> seq(string s1, string s2){
        int l = min(s1.length(), s2.length());
        string s="";
        for(int i=0;i<l;i++){
            //cout<<s1[i]<<" "<<s2[i]<<endl;
            if(s1[i] != s2[i])
            return {s1[i],s2[i]};
            
        }
        return {'#','#'};
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=1;i<N;i++){
            pair<char,char> s = seq(dict[i-1], dict[i]);
            //cout<<s.first<<" "<<s.second<<endl;
            if(s.first != '#'){
                
                adj[s.first - 'a'].push_back(s.second - 'a');
            }
        }
        // for(int i=0;i<K;i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<adj[i].size();j++)
        //     cout<<adj[i][j]<<" ";
        //     cout<<endl;
        // }
        
        vector<int> ans;
	    vector<int> in(K,0);
	    queue<int> q;
	    for(int i=0;i<K;i++){
	        for(auto x:adj[i]){
	            in[x]++;
	        }
	    }
	    for(int i=0;i<K;i++){
	        if(in[i] == 0)
	        q.push(i);
	    }
	    while(!q.empty()){
	        int t = q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto x:adj[t]){
	            in[x]--;
	            if(in[x]==0)
	            q.push(x);
	        }
	    }
	    
	    string s = "";
	    for(int i=0;i<ans.size();i++){
	        char ch=ans[i]+'a';
	        s=s+ch;
	    }
	    //return ans;
        
        return s;
    }
};

