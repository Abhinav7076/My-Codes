class Solution
{
    public:
        bool zeros(int count, int n){
            if(count==0)
            return 0;
            int sum=0;
           for(int i=5;i<=n;i=i*5){
                sum = sum + floor(n/i);
                if(sum>=count)
                return true;
            }
            return false;
             
        }
        
        int findNum(int n)
        {
        //complete the function here
        int low=0;
        int high=5*n;
        
        while(low<high){
            //cout<<low<<" "<<high<<endl;
            int mid=(low+high)/2;
            
            if(zeros(n,mid))
            high=mid;
            else
            low=mid+1;
        }
        return low;
        }
};