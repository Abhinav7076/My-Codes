class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {
        // Your code here
        int u[3]={0};
        for(int i=0;i<x.length();i++){
            if(x[i]=='(')
            u[0]++;
            else if(x[i]==')')
            u[0]--;
            else if(x[i]=='{')
            u[1]++;
            else if(x[i]=='}')
            u[1]--;
            else if(x[i]=='[')
            u[2]++;
            else if(x[i]==']')
            u[2]--;
        }
        for(int i=0;i<3;i++){
            if(u[i]!=0)
            return false;
        }
        return true;
    }

};
