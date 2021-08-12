class Solution{
  public:
    // This function returns true if str1 and str2 are ismorphic
    // else returns false
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char, char> u;
        
        
        for(int i=0;i<str1.length();i++){
            u[str1[i]]=str2[i];
            }
        
        string str="";
        
        for(int i=0;i<str1.length();i++){
            str= str + u[str1[i]];
            }
        
        unordered_map<char, char> u2;
        
        
        for(int i=0;i<str2.length();i++){
            u[str2[i]]=str1[i];
            }
        
        string s2="";
        
        for(int i=0;i<str2.length();i++){
            s2= s2 + u[str2[i]];
            }
        
        
       // cout<<str;
        if(str==str2 and s2==str1)
        return true;
        else
        return false;
    }
};