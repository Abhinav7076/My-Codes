class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        string str="";
        int c=0;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                str=str+s[i-1];
            }
        }
        str=str+s[s.length()-1];
        return str;
    }
};