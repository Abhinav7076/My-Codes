class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here
        if(n==0)
        return false;
        double p = log2(n);
        if(p == floor(p))
        return true;
        else
        return false;
        
    }
};