class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        return min(max(A,B),min(max(A,C),max(B,C)));
    }
};