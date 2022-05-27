// sort on the basis of w/v
struct Item{
    int value;
    int weight;
};

bool compareProfit(Item a, Item b)
    {
        double x = (double)a.value/a.weight;
        double y = (double)b.value/b.weight;
        
        return x>y;
    }

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,compareProfit);
        //for(int i=0;i<n;i++)
        //cout<<arr[i].value<<" "<<(double)arr[i].value/arr[i].weight<<" "<<endl;
                
        int i=0;
        double profit=0;
        while(W>0 and i<n){
            int wt = arr[i].weight;
            if(wt<=W){
                profit = profit + (double)arr[i].value;
                W=W-wt;
                //cout<<profit<<" "<<W<<endl;
                
            }
            else{
                profit = profit + (double)(arr[i].value*W)/(double)wt;
                W=0;
            }
            i++;
        }
        return profit;
    }
        
};


int main()
{
    int t;
    //taking testcases
    cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        //size of array and weight
        int n, W;
        cin>>n>>W;
        
        Item arr[n];
        //value and weight of each item
        for(int i=0;i<n;i++){
            cin>>arr[i].value>>arr[i].weight;
        }
        
        //function call
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
} 