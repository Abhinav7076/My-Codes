// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
int minimumDays(int S, int N, int M){
        // code here
    if (((N * 6) < (M * 7) && S > 6) || M > N)
	return -1;
	else {
		// If we can survive then we can
		// buy ceil(A/N) times where A is
		// total units of food required.
		int days = ceil((double)(M * S) / N);
	return days;
    }
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}
