// Input: arr[] = {1, 8, 2, 3, 4, 5, 7, 20}
// Output: 7 5 2 3 4 8 1 20
// Explanation:
// The output consists of all the prime numbers 7 5 2 3, followed by Non-Prime numbers 4 8 1 20.

// Input: arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}
// Output: 2 3 7 5 6 4 8 9 10

// C++ program for the above approach
#include <iostream>
using namespace std;

// Function to swap two numbers a and b
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Function to check if a number n
// is a prime number of not
bool isPrime(int n)
{
	// Edges Cases
	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	// To skip middle five numbers
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	// Checks for prime or non prime
	for (int i = 5;
		i * i <= n; i = i + 6) {

		// If n is divisible by i
		// or i + 2, return false
		if (n % i == 0
			|| n % (i + 2) == 0)
			return false;
	}

	// Otherwise, the
	// number is prime
	return true;
}

// Function to segregate the primes
// and non-primes present in an array
void segregatePrimeNonPrime(
	int arr[], int N)
{
	// Initialize left and right pointers
	int left = 0, right = N - 1;

	// Traverse the array
	while (left < right) {

		// Increment left while array
		// element at left is prime
		while (isPrime(arr[left]))
			left++;

		// Decrement right while array
		// element at right is non-prime
		while (!isPrime(arr[right]))
			right--;

		// If left < right, then swap
		// arr[left] and arr[right]
		if (left < right) {

			// Swapp arr[left] and arr[right]
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}

	// Print segregated array
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 2, 3, 4, 6, 7, 8, 9, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);

	segregatePrimeNonPrime(arr, N);

	return 0;
}
// Time Complexity: O(N*log(log(N)))

// C++ program for the above approach
#include <iostream>
using namespace std;

// Function to swap two numbers a and b
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Function to check if a number n
// is a prime number of not
bool isPrime(int n)
{
	// Edges Cases
	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	// To skip middle five numbers
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	// Checks for prime or non prime
	for (int i = 5;
		i * i <= n; i = i + 6) {

		// If n is divisible by i
		// or i + 2, return false
		if (n % i == 0
			|| n % (i + 2) == 0)
			return false;
	}

	// Otherwise, the
	// number is prime
	return true;
}

// Function to segregate the primes
// and non-primes present in an array
void segregatePrimeNonPrime(
	int arr[], int N)
{
	// Initialize left and right pointers
	int left = 0, right = N - 1;

	// Traverse the array
	while (left < right) {

		// Increment left while array
		// element at left is prime
		while (isPrime(arr[left]))
			left++;

		// Decrement right while array
		// element at right is non-prime
		while (!isPrime(arr[right]))
			right--;

		// If left < right, then swap
		// arr[left] and arr[right]
		if (left < right) {

			// Swapp arr[left] and arr[right]
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}

	// Print segregated array
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 2, 3, 4, 6, 7, 8, 9, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);

	segregatePrimeNonPrime(arr, N);

	return 0;
}

// Time Complexity: O(N*sqrt(N))