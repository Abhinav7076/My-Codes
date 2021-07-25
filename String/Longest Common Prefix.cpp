class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)
            return "";
        
        if(strs.size()==1)
            return strs[0];
        
        int mi = INT_MAX, s_index=0;
        for(int i=0;i< strs.size();i++){
            if(strs[i].length()<mi){
                mi = strs[i].length();
                s_index=i;
            }
        }
        int count=0,f=0;
        for(int i=0;i<mi;i++){
            char ch=strs[s_index][i];
            int c=0;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]==ch)
                    c++;
                else{
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
            cout<<c<<endl;
            if(c==strs.size())
                count++;
        }
        return strs[s_index].substr(0,count);
    }
};