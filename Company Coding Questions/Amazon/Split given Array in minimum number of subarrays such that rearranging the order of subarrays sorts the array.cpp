// C++ program for the above approach

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Function to find minimum number of
// subarrays such that rearranging the
// subarrays sort the array
int numberOfSubarrays(int arr[], int n)
{
	// Stores the minimum number of
	// subarrays
	int cnt = 1;

	// Stores all the elements in the
	// array with their indices
	vector<pair<int, int> > v(n);

	// Copy array elements in vector
	for (int i = 0; i < n; i++) {
		v[i].first = arr[i];
		v[i].second = i;
	}

	// Sort the vector v
	sort(v.begin(), v.end());

	// Iterate through vector v
	for (int i = 1; i < n; i++) {

		// If the (i)th and (i-1)th element
		// can be grouped in same subarray
		if (v[i].second == v[i - 1].second + 1) {
			continue;
		}
		else {
			cnt++;
		}
	}

	// Return resultant count
	return cnt;
}

// Driver Code
int main()
{
	int arr[] = { 6, 3, 4, 2, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << numberOfSubarrays(arr, N);

	return 0;
}
