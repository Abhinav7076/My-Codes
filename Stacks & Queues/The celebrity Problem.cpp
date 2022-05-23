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


public class Solution extends Relation {
    public int findCelebrity(int n) {
        // Compare and eliminate one that is not celebrity. Compare with the next number until reaching the last number.
        int candidate = 0;
        for (int j = 1; j < n; j++)
            if (knows(candidate, j)) {
                candidate = j; // We get a final candidate by linear comparison
            }

        // Check if the final candidate is the celebrity
        for (int k = 0; k < n; k++) {
            if (candidate == k) continue;
            if (knows(candidate, k) || !knows(k, candidate)) { // If it knows someone, or someone doesn't know it, it's not a celebrity
                return -1;
            }
        }
        return candidate;
    }
}