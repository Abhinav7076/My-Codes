class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
 
int solve(int n, int &sum){
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    int p = (int)log2(n);
    int h = findPower(2,p-1,1e9+7);
    
    return sum = p*h + n - h*2 + 1 + solve(n-2*h,sum);
}
int findPower(long long base, unsigned int exponent, int mod){
    int result=1;
    base=base%mod;
    if(base==0)
    return 0;
    
    while(exponent>0){
        if(exponent & 1)
        result = (result*base)%mod;
        
        exponent=exponent>>1;
        base=(base*base)% mod;
    }
    return result;
}

    int countSetBits(int n)
    {
        // Your logic here
       
        int sum=0;
        return solve(n,sum);
    }
};
