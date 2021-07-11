class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        static int a[2];
        unordered_map<int, int> u;
        for(int i=0;i<n;i++){
            u[arr[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(u[i]==2){
            a[0]=i;
            }
            if(u[i]==0)
            a[1]=i;
        }
        return a;
    }
};