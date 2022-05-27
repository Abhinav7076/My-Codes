// CPP program to find minimum number of
// elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution{
    public:
    int minSubset(vector<int> &arr,int N){
        if(N==1)
        return 1;
        sort(arr.begin(), arr.end());
        long long int sum = accumulate(arr.begin(), arr.end(), 0ll);
        long long int subsetsum = 0, res = 0;
        for(int i=N-1;i>=0;i--){
            subsetsum += arr[i];
            sum -= arr[i];
            res++;
            if(subsetsum>sum)
                return res;
        }
        return N; //0 0 <-TC
    }
};

// Driver function
int main()
{
	int arr[] = {3, 1, 7, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minElements(arr, n) << endl;
	return 0;
}
