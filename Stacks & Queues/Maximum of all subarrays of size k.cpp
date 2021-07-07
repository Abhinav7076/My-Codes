class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> v;
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty() and arr[q.back()] < arr[i])
            q.pop_back();
            
            q.push_back(i);
        }
        v.push_back(arr[q.front()]);
        for(int i=k;i<n;i++){
            if(q.front() == i-k)
            q.pop_front();
            
            while(!q.empty() and arr[q.back()] < arr[i])
            q.pop_back();
            
            q.push_back(i);
            v.push_back(arr[q.front()]);
        }
        return v;
    }
};
