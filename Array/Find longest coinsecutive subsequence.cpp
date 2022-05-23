// Create an empty hash.
// Insert all array elements to hash.
// Do following for every element arr[i]
// Check if this element is the starting point of a subsequence. 
// To check this, simply look for arr[i] – 1 in the hash, 
// if not found, then this is the first element a subsequence.
// If this element is the first element, then count the number 
// of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
// If the count is more than the previous longest subsequence found, 
// then update this.

int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
        unordered_map<int, int> u;
        int ans = 0;
     
        // Hash all the array elements
        for (int i = 0; i < n; i++)
            u[arr[i]]++;
     
        // check each possible sequence from
        // the start then update optimal length
        for (int i = 0; i < n; i++)
        {
            // if current element is the starting
            // element of a sequence 
            // arr[i] starting element hoga agar arr[i] - 1 nahi present hais
            if (!u[arr[i] - 1])
            {
                // Then check for next elements
                // in the sequence
                int j = arr[i];
                while (u[j])
                    j++;
     
                // update  optimal length if
                // this length is more
                ans = max(ans, j - arr[i]);
            }
        }
        return ans;
    }

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