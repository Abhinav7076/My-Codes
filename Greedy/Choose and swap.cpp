// find the lexicographically smallest string that can be obtained by doing this operation at most once.
class Solution{
public:
    string chooseandswap(string str){
        // Code Heres
        int n = str.length();
        set<char> s;
        for(int i=0;i<n;i++)
            s.insert(str[i]);
        for(int i=0;i<n;i++){
            s.erase(str[i]);
            if(s.empty())
            break;
            char ch = *s.begin();
            char ch2 = str[i];
            if(ch < str[i]){
                for(int j=0;j<n;j++){
                    if(str[j] == ch)
                    str[j] = ch2;
                    else if(str[j] == ch2)
                    str[j] = ch;
                }
                break;
            }
        }
        return str;
    }
    
};
