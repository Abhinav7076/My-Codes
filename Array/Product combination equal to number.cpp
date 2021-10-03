// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find all unique combination of
// given elements such that their sum is K
void unique_combination(int l, int sum, int K,
						vector<int>& local,
						vector<int>& A)
{
	// If a unique combination is found
	if (sum == K) {
		cout << "{";
		for (int i = 0; i < local.size(); i++)
		{
			if (i != 0)
				cout << " ";
			cout << local[i];
			if (i != local.size() - 1)
				cout << ", ";
		}
		cout << "}" << endl;
		return;
	}

	// For all other combinations
	for (int i = l; i < A.size(); i++)
	{

		// Check if the sum exceeds K
		if (sum + A[i] > K)
			continue;

		// Check if it is repeated or not
		if (i > l and A[i] == A[i - 1])
			continue;

		// Take the element into the combination
		local.push_back(A[i]);

		// Recursive call
		unique_combination(i + 1, sum + A[i], K, local, A);

		// Remove element from the combination
		local.pop_back();
	}
}

// Function to find all combination
// of the given elements
void Combination(vector<int> A, int K)
{
	// Sort the given elements
	sort(A.begin(), A.end());

	// To store combination
	vector<int> local;

	unique_combination(0, 0, K, local, A);
}

// Driver code
int main()
{
	vector<int> A = { 10, 1, 2, 7, 6, 1, 5 };

	int K = 8;

	// Function call
	Combination(A, K);

	return 0;
}
