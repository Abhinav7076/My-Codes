class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = pow(2,s.length());
		    vector<string> v;
		    for(int i=1;i<n;i++){
		        bitset<16> b(i);
		        string str="";
		        for(int j=0;j<16;j++){
		            if(b[j]==1){
		                str+=s[j];
		            }
		        }
		        v.push_back(str);
		    }
		    sort(v.begin(), v.end());
		    return v;
		    
		}
};