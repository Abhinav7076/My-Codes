//evaluate reverse polish
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> st;
        int result=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                int cal=0;
                //cout<<t1<<" "<<t2<<endl;
                if(tokens[i] == "+")
                    cal=t1+t2;
                else if(tokens[i] == "-")
                    cal=t2-t1;
                else if(tokens[i] == "*")
                    cal=t1*t2;
                else if(tokens[i] == "/")
                    cal=t2/t1;
                
                st.push(cal);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};