int countRev (string s)
{
    // your code here
    if(s.length()%2 == 1)
    return -1;
    
    stack<char> st;
    int c=0,c2=0; //c for counting } nand c2 for counting {
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='{'){
            st.push(ch);
            c2++;
        }
        else if(ch=='}' and !st.empty() and st.top()=='{'){
            st.pop();
            c2--;
        }
        else c++;
    }
    if(c&1)
    c=(c/2)+1;
    else
    c=c/2;
    
    if(c2&1)
    c2=(c2/2)+1;
    else
    c2=c2/2;
    return c+c2;
    
}