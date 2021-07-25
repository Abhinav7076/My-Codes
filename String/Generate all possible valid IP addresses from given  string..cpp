
class Solution{
  public:
  
  bool inRange(int n){
      if(n>=0 and n<=255)
      return true;
      return false;
  }
  bool noLeadingZeros(string s){
      int index = 0,c=0,n=s.length();
      for(int i=0;i<s.length();i++){
          if(s[i] != '0'){
              index = i;
              break;
          }
          else{
              c++;
          }
      }
      if(c==1 and c==n)
          return true;
      if(index==0 and c!=n)
      return true;
      return false;
  }
    void isValidIP(int i,int j,int k,string s, vector<string> &v){
      string s1 = string(s.begin(), s.begin() + i + 1);
      string s2 = string(s.begin() + i + 1, s.begin() + j + 1);
      string s3 = string(s.begin() + j + 1, s.begin() + k + 1);
      string s4 = string(s.begin() + k + 1, s.end());
    //   string str = s1+"."+s2+"."+s3+"."+s4;
    //   cout<<str<<endl;
      if(s1.length()<=3 and s2.length()<=3 and s3.length()<=3 and s4.length()<=3){
          if(noLeadingZeros(s1) and noLeadingZeros(s2) and noLeadingZeros(s3) and noLeadingZeros(s4)){
              if(inRange(stoi(s1)) and inRange(stoi(s2)) and inRange(stoi(s3)) and inRange(stoi(s4))){
                  string str = s1+"."+s2+"."+s3+"."+s4;
                  v.push_back(str);
              }
          }
      }
      return;
  }
  
  
    vector<string> genIp(string &s) {
        // Your code here
         int n = s.length();
        vector<string> v;
        if(n<4 or n>12)
        return v;
        
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    isValidIP(i,j,k,s,v);
                }
            }
        }
        
        return v;
    }

};