// The idea is to use the fact that inorder traversal of Binary Search Tree is in ascending order of their value. 
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer

// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,
						int n, int index)
{
	// if index is greater or equal to vector size
	if(index >= n)
		return;
	inorder(a, v, n, 2 * index + 1);
	
	// push elements in vector
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int> > v;
	    int n = nums.size(), ans = 0;
	    for(int i=0;i<n;i++){
	        v.push_back({nums[i], i});
	    }
	    sort(v.begin(), v.end());
	    vector<bool> visited(n);
	    
	    for(int i=0;i<n;i++){
	        if(visited[i] or v[i].second == i) //if it is right position
	            continue;
	        
	        // find out the number of  node in
        	// this cycle and add in ans
	        int cycle_len=0;
	        int j=i;
	        while(visited[j] == false){
	            visited[j] = true;
	            cycle_len++;
	            j = v[j].second;
	        }
	        ans += cycle_len - 1;
	        
	    }
	    return ans;
	}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	std::vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v) << endl;
}

// This code is contributed by code_freak
