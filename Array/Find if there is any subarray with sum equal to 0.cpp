class Solution{
    public:
    //Complete this function
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int> s;
        int sum=0;
        bool found=false;
        for(int i=0;i<n;i++){
            s.insert(sum);
            sum+=arr[i];
            if(s.find(sum)!=s.end()){
                found=true;
                break;
            }
        }
        return found;
        
        
    }
};
