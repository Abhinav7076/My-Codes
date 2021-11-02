// Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
// Traverse the array from start to end and mid is less than high. (Loop counter is i)
// If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
// If the element is 1 then update mid = mid + 1
// If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
// Print the output array.
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}


void sort012(int a[], int n)
    {
        // coode here
        int count[3]={0};
        
        
        for(int i=0;i<n;i++){
            count[a[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<count[i];j++)
            a[index++]=i;
        }
        
        
    }