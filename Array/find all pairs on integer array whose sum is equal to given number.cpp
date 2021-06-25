class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int x = k - arr[i];
            if(m[x]==0){
                m[arr[i]]++;
            }
            else{
                count+=m[x];
                m[arr[i]]++;
            }
        }
    
        return count;
    }
};