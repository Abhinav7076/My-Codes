class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if(n<=2)
        return false;
        
        sort(A,A+n);
        
        for(int i=0;i<n-2;i++){
            
            int l=i+1;
            int r=n-1;
            
            //cout<<A[i]<<" "<<A[l]<<" "<<r<<" "<<A[r]<<" "<<endl;
            while(l<r){
                if(A[i]+A[l]+A[r]==X)
                return true;
                else if(A[i]+A[l]+A[r]<X)
                l++;
                else
                r--;
            }
        }
        
        return false;
    }

};