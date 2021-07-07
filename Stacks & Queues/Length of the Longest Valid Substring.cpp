class Solution {
  public:
    int findMaxLen(string s) {
        // code here'
        stack<char> st;
        stack<int> idx;
        int len=0,ma=0;
        idx.push(-1); //trick
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push('(');
                idx.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                    idx.pop();
                    len = i - idx.top();
                    ma=max(len,ma);
                }
                else{
                    idx.push(i);
                }
            }
        }
        return ma;
        
    }
};