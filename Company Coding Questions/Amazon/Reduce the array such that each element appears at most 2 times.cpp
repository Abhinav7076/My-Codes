// C++ program to reduce the array
// such that each element appears
// at most 2 times

#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates
void removeDuplicates(int arr[], int n)
{
	// Initialise 2nd pointer
	int st = 0;

	// Iterate over the array
	for (int i = 0; i < n; i++) {

		if (i < n - 2
			&& arr[i] == arr[i + 1]
			&& arr[i] == arr[i + 2])
			continue;

		// Updating the 2nd pointer
		else {
			arr[st] = arr[i];
			st++;
		}
	}

	cout << "{";
	for (int i = 0; i < st; i++) {
		cout << arr[i];

		if (i != st - 1)
			cout << ", ";
	}
	cout << "}";
}

// Driver code
int main()
{
	int arr[]
		= { 1, 1, 1, 2,
			2, 2, 3, 3,
			3, 3, 3, 3,
			4, 5 };

	int n = sizeof(arr)
			/ sizeof(arr[0]);

	// Function call
	removeDuplicates(arr, n);

	return 0;
}
