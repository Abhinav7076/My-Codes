class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int a = ceil((double)N/(K+1));
        int ans1=accumulate(candies , candies+a , 0);
        
        reverse(candies,candies+N);
        int ans2=accumulate(candies , candies+a , 0);
        
        return {ans1,ans2};
        
    }
};
