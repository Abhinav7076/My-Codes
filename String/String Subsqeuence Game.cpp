class Solution {
  public:
  bool startVowelEndConsonant(string s){
      int n = s.length()-1;
      if((s[0] == 'a' or s[0] == 'e' or s[0] == 'i' or s[0] == 'o' or s[0] == 'u') and (s[n] != 'a' and s[n] != 'e' and s[n] != 'i' and s[n] != 'o' and s[n] != 'u'))
      return true;
      return false;
  }
  void subseq(string input, string output, vector<string> &v){
      if(input.empty()){
          v.push_back(output);
          return;
      }
      subseq(input.substr(1), output + input[0], v); //include first character
      subseq(input.substr(1), output, v);  //exclude first character
  }
    set<string> allPossibleSubsequences(string S) {
        // code here
        vector<string> v;
        set<string> s;
        subseq(S,"",v);
        
        for(int i=0;i<v.size();i++){
            if(startVowelEndConsonant(v[i]))
            s.insert(v[i]);
        }
        
        return s;
    }
};