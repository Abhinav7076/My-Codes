// ((a+b))
// (a+(b)/c)
// (a+b*(c-d))
// Output: 
// Yes
// Yes
// No

// Since, it is given that the expression is always valid, 
// we can infer that any pair of valid braces must contain
// at least 1 operator and 1 operand in order to be 
// valid parenthesis. Thus, it will be enough to 
// check that if a pair of braces contains at least 2 characters
// or not in order to check redundancy (as all are binary operators).


#include<bits/stdc++.h>
using namespace std;

bool checkRedundancy(string A) {
	stack<char> st;
	for(char ch : A)
	{
		if(ch == ')')
		{
			int cnt = 0;
			while(!st.empty() and st.top() != '(')
			{
				cnt++;
				st.pop();
			}
			st.pop();
			if(cnt < 2) return 1;
		}
		else st.push(ch);
	}

	return 0;
}

int main()
{
	string str = "((a+b))";
	cout<<checkRedundancy(str)<<"\n";

	str = "(a+(b)/c)";
	cout<<checkRedundancy(str)<<"\n";

	str = "(a+b*(c-d))";
	cout<<checkRedundancy(str)<<"\n";

	return 0;
}
