class Solution{
public:

    vector<long long int> getMaxandMinProduct(long long int arr[], long long int n)
    {
        // Your code goes here
        long long int curMaxProduct = arr[0];
        long long int curMinProduct = arr[0];
        long long int prevMaxProduct = arr[0];
        long long int prevMinProduct = arr[0];
        long long int maxProduct = arr[0];
        long long int minProduct = arr[0];
     
        // Process all elements after arr[0]
        for (long long int i = 1; i < n; ++i)
        {
            /* Current maximum product is maximum of following
                1) prevMax * curelement (when curelement is +ve)
                2) prevMin * curelement (when curelement is -ve)
                3) Element itself
                4) Previous max product */
            curMaxProduct = max(prevMaxProduct * arr[i],
                                max(prevMinProduct * arr[i],
                                    arr[i]));
            curMaxProduct = max(curMaxProduct, prevMaxProduct);
     
            /* Current min product computation is Similar to
               that of current max profuct     */
            curMinProduct = min(prevMaxProduct * arr[i],
                                min(prevMinProduct * arr[i],
                                    arr[i]));
            curMinProduct = min(curMinProduct, prevMinProduct);
            maxProduct = max(maxProduct, curMaxProduct);
            minProduct = min(minProduct, curMinProduct);
     
            // copy current values to previous values
            prevMaxProduct = curMaxProduct;
            prevMinProduct = curMinProduct;
        }
     
        vector<long long int> v;
        v.push_back(minProduct);
        v.push_back(maxProduct);
        return v;
    }  
};