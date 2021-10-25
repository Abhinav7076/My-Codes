bool ispar(string x)
    {
        // Your code here
        int n = x.length();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(x[i] == '[' or x[i] == '{' or x[i] == '(')
            s.push(x[i]);
            else if(x[i] == ')'){
                if(!s.empty() and s.top() == '(')
                s.pop();
                else
                return false;
            }
            else if(x[i] == '}'){
                if(!s.empty() and s.top() == '{')
                s.pop();
                else
                return false;
            }
            else if(x[i] == ']'){
                if(!s.empty() and s.top() == '[')
                s.pop();
                else
                return false;
            }
        }
        if(!s.empty())
        return false;
        return true;
    }