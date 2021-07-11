class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        unordered_map<int,int> u;
        for(int i=0;i<size;i++)
            u[a[i]]++;
            
        unordered_map<int,int>::iterator it;
        for(it=u.begin();it!=u.end();it++){
            if(it->second > size/2)
            return it->first;
        }
        return -1;
        
    }
};