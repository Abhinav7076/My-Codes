// Method 2 (By comparing the medians of two arrays) 
// This method works by first getting medians of the two sorted arrays and then comparing them.
// Let ar1 and ar2 be the input arrays. 

// 1) Calculate the medians m1 and m2 of the input arrays ar1[] 
//    and ar2[] respectively.
// 2) If m1 and m2 both are equal then we are done.
//      return m1 (or m2)
// 3) If m1 is greater than m2, then median is present in one 
//    of the below two subarrays.
//     a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
//     b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
// 4) If m2 is greater than m1, then median is present in one    
//    of the below two subarrays.
//    a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
//    b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
// 5) Repeat the above process until size of both the subarrays 
//    becomes 2.
// 6) If size of the two arrays is 2 then use below formula to get 
//   the median.
//     Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2

int getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */
 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}
 
/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
 