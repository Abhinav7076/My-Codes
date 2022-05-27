// Push the first element to stack.
// Pick rest of the elements one by one and follow following steps in loop.
// Mark the current element as next.
// If stack is not empty, then compare next with stack top. If next is smaller than top then next is the NSE for the top. Keep popping from the stack while top is greater than next. next becomes the NSE for all such popped elements
// Push next into the stack
// After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

// A Stack based C++ program to find next
// smaller element for all array elements
#include <bits/stdc++.h>
using namespace std;

// prints NSE for elements of array arr[] of size n

vector<int> help_classmate(vector<int> A, int n) 
    { 
        // Your code goes here
        vector<int> R(n, -1);
        stack<int> S;
        for (int i = 0; i < n; i++) {
            while (S.size() && A[S.top()] > A[i]) {
                R[S.top()] = A[i];
                S.pop();
            }
            S.push(i);
        }
        return R;
    } 

void printNSE(int arr[], int n)
{
	stack<pair<int, int> > s;
	vector<int> ans(n);

	// iterate for rest of the elements
	for (int i = 0; i < n; i++) {
		int next = arr[i];

		// if stack is empty then this element can't be NSE
		// for any other element, so just push it to stack
		// so that we can find NSE for it, and continue
		if (s.empty()) {
			s.push({ next, i });
			continue;
		}

		// while stack is not empty and the top element is
		// greater than next
		// a) NSE for top is next, use top's index to
		// maintain original order
		// b) pop the top element from stack

		while (!s.empty() && s.top().first > next) {
			ans[s.top().second] = next;
			s.pop();
		}

		// push next to stack so that we can find NSE for it

		s.push({ next, i });
	}

	// After iterating over the loop, the remaining elements
	// in stack do not have any NSE, so set -1 for them

	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ---> " << ans[i] << endl;
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}
