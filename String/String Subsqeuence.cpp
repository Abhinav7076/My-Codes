class Solution{
public:
    int count(string X, string Y, int m, int n)
{
    // Base case 1: if only one character is left
    if (m == 1 && n == 1) {
        return (X[0] == Y[0]);
    }
 
    // Base case 2: if the input string `X` reaches its end
    if (m == 0) {
        return 0;
    }
 
    // Base case 3: if pattern `Y` reaches its end, we have found subsequence
    if (n == 0) {
        return 1;
    }
 
    // Optimization: the solution is not possible if the number of characters
    // in the string is less than the number of characters in the pattern
    if (n > m) {
        return 0;
    }
 
    /*
      If the last character of both string and pattern matches,
        1. Exclude the last character from both string and pattern
        2. Exclude only the last character from the string.
    
      Otherwise, if the last character of the string and pattern do not match,
      recur by excluding only the last character in the string
    */
 
    return ((X[m - 1] == Y[n - 1]) ? count(X, Y, m - 1, n - 1) : 0) +
        count(X, Y, m - 1, n);
}
    int countWays(string s1, string s2){
        // code here
        
        return count(s1,s2,s1.length(), s2.length());
    }
};