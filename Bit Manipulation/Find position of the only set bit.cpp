class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n==0)
        return -1;
        double x = log2(n);
        if(x == floor(x)){
            return x+1;
        }
        else
        return -1;
    }
};