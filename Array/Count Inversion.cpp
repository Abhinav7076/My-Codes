class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
        long long merge(long long arr[],long long l, long long mid, long long r){
        long long inv=0,n1,n2;
        n1=mid-l+1;
        n2=r-mid;
        
        long long a1[n1];
        long long a2[n2];
        
        for(long long i=0;i<n1;i++)
        a1[i]=arr[i+l];
        
        for(long long i=0;i<n2;i++)
        a2[i]=arr[mid+1+i];
        
        long long i=0,j=0,k=l;
        
        while(i<n1 && j<n2){
            if(a1[i]<=a2[j]){
                arr[k]=a1[i];
                i++;
                k++;
            }
            //a[i]>a[j]
            else{
                arr[k]=a2[j];
                inv+=n1-i;
                j++;
                k++;
            }
        }
        
        while(i<n1){
                arr[k]=a1[i];
                i++;
                k++;
        }
        while(j<n2){
                arr[k]=a2[j];
                j++;
                k++;
        }
        return inv;
        
    }
    
    
    long long mergeSort(long long arr[], long long l, long long r){
        long long inv=0;
        if(l<r){
            long long mid=(l+r)/2;
            inv+=mergeSort(arr,l,mid);
            inv+=mergeSort(arr,mid+1,r);
            inv+=merge(arr,l,mid,r);
        }
        return inv;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long inv=0;
        inv=mergeSort(arr,0,N-1);
        return inv;
    }

    

};