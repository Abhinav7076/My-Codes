#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    // this solution uses two heaps to store values. somewhat
    // nonintuitively, the "max" heap will store all values 
    // below the median, and the "min" heap will store all values
    // above the median. In this fashion the median will ultimately
    // always be available by looking at the tops of the two heaps.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        // If the max Heap is empty, then insert into 
        // the max heap.
        if(maxHeap.empty()) {
            maxHeap.push(x);
            return;
        }

        // If the value is less than or equal to the
        // maximum in the max-heap, that means that the
        // max heap should store this value. Otherwise,
        // store the value in the min heap.
        if(x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }

        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // Compare the size of the two heaps to ensure that
        // the two heaps are always within one size of
        // each other
        while(abs(int(maxHeap.size() - minHeap.size())) > 1) {
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        else if(maxHeap.size() < minHeap.size())
            return minHeap.top();
        else
            return 0.5*(minHeap.top() + maxHeap.top());
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends