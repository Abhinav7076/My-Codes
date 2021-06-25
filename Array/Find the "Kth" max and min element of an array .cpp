int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    int n=r-l+1;
    sort(arr,arr+n);
    
    
    return arr[k-1];
    
}