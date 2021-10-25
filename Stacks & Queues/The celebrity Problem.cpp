class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++)
        s.push(i);
        
        while(s.size()!=1){
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if(M[a][b]==0) //agar a b ko nahi janta to b celebrity nahi hoga
            s.push(a);
            else if(M[a][b]==1) //agar a b ko janta hai to a celebrity nhi hoga
            s.push(b);
        }
        int cel = s.top();
        for(int i=0;i<n;i++){
            if(M[cel][i])
            return -1;
            if(i!=cel and M[i][cel]==0)
            return -1;
        }
        return cel;
    }
};