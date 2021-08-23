class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        int arr[n+1][2] = {0};
        for(int i=0;i<2*e;i=i+2){
            if(arr[A[i]][0]==0)
            arr[A[i]][0] = A[i+1];
            else
            arr[A[i]][1] = A[i+1];
        }
        
        int b[n+1][2] = {0};
        for(int i=0;i<2*e;i=i+2){
            if(b[B[i]][0]==0)
            b[B[i]][0] = B[i+1];
            else
            b[B[i]][1] = B[i+1];
        }
        

        for(int i=1;i<=n;i++){
            if(arr[i][1]!=0 and arr[i][0]!=b[i][1])
            return 0;
            if(arr[i][1]!=0 and arr[i][1]!=b[i][0])
            return 0;
        }
        
        return 1;
    }
};
