int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}

// Time Complexity: O(log n + log m)

 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(arr2, arr1, m, n, k);
        
        int low = max(0, k-m), high = min(k, n);
        
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(l1<=r2 and l2<=r1)
                return max(l1, l2);
            else if(l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0;
        
    }
};

// Time Complexity: O(min(log n + log m))