class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        // Your code here
        stack<int> s;
        for(int i=0;i<str.length();i++){
            if(str[i] == '+' or str[i]=='-' or str[i]=='*' or str[i]=='/'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int cal = 0;
                if(str[i]=='+')
                cal=a+b;
                else if(str[i]=='-')
                cal=b-a;
                else if(str[i]=='*')
                cal=a*b;
                else if(str[i]=='/')
                cal=b/a;
                
                s.push(cal);
            }
            else
            s.push((int)(str[i]-'0'));
        }
        return s.top();
        
    }
};