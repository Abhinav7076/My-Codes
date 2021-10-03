// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the lexicographically
// largest sub-sequence of s
string getSubSeq(string s, int n)
{
    string res = "";
    int cr = 0;
    while (cr < n) {

        // Get the max character from the string
        char mx = s[cr];
        for (int i = cr + 1; i < n; i++)
            mx = max(mx, s[i]);
        int lst = cr;

        // Use all the occurrences of the
        // current maximum character
        for (int i = cr; i < n; i++)
            if (s[i] == mx) {
                res += s[i];
                lst = i;
            }

        // Repeat the steps for the remaining string
        cr = lst + 1;
    }
    return res;
}

// Driver code
int main()
{
    string s = "geeksforgeeks";
    int n = s.length();
    cout << getSubSeq(s, n);
}
