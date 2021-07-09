class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n=r-l+1;
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
            if(q.size()>k)
            q.pop();
        }
        return q.top();
    }
};