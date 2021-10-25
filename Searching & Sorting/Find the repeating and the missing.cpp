void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

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