class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++)
                v.push_back(arr[i][j]);
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//method 2
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > q;
        for(int i=0;i<K;i++){
            q.push(make_tuple(arr[i][0],0,i));
        }
        //element, index, array no
        
        while(!q.empty()){
            int n,index,arr_no;
            tie(n,index,arr_no) = q.top();
            q.pop();
            v.push_back(n);
            if(index+1<K)
            q.push(make_tuple(arr[arr_no][index+1], index+1,arr_no));
        }
        
        return v;
    }
};