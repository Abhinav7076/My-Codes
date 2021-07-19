class Solution {
public:
    string countAndUpdate(string s){
        int c=1;
        
        string str="";
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])
                c++;
            else{
                char ch = c + '0';
                str = str + ch + s[i-1];
                c=1;
            }
        }
        char ch = c + '0';
        str = str + ch + s[s.length()-1];
        // cout<<str<<endl;
        return str;
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string ans="11";
        for(int i=0;i<n-2;i++){
            ans = countAndUpdate(ans);
        }
        return ans;
    }
};