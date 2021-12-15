// C++ program for Fibonacci Series
// using Dynamic Programming
#include<bits/stdc++.h>
using namespace std;

class GFG{
	
public:
int fib(int n)
{
	
	// Declare an array to store
	// Fibonacci numbers.
	// 1 extra to handle
	// case, n = 0
	int f[n + 2];
	int i;

	// 0th and 1st number of the
	// series are 0 and 1
	f[0] = 0;
	f[1] = 1;

	for(i = 2; i <= n; i++)
	{
		
	//Add the previous 2 numbers
	// in the series and store it
	f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
	}
};

// Driver code
int main ()
{
	GFG g;
	int n = 9;
	
	cout << g.fib(n);
	return 0;
}

// This code is contributed by SoumikMondal

#include<iostream>
#include<cmath>
 
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
 
// Driver Code
int main ()
{
  int n = 9;
  std::cout << fib(n) << std::endl;
  return 0;
}
//-----------------------------------------------------------
// O(log n)

#include<iostream>
#include<cmath>
 
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
 
// Driver Code
int main ()
{
  int n = 9;
  std::cout << fib(n) << std::endl;
  return 0;
}

//-----------------------------------------------------------
//Fibonacci Series using Recursion
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n-1) + fib(n-2);
}

int main ()
{
	int n = 9;
	cout << fib(n);
	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai

// O(n)