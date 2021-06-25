class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int present[100001]={0};
      for(int i=0;i<N;i++){
          present[arr[i]]=1;
      }
      
      int maxlength=0,length=0;
      for(int i=1;i<=100000;i++){
          if(present[i]==1)
          length++;
          else{
          maxlength=max(maxlength,length);
          length=0;
          }
      }
      if(length==100000)
      return length;
      
      return maxlength;
    }
};