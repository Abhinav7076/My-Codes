class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    void print(vector<vector<int> > v){
    cout<<"Print\n";
    for(int i=0;i<v.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int> > v;
        int bd=0,sd=0,profit=0;
        for(int i=1;i<n;i++){
            if(A[i] > A[i-1])
            sd++;
            else{
                vector<int> vec;
                vec.push_back(bd);
                vec.push_back(sd);
                v.push_back(vec);
                profit+=A[sd] - A[bd];
                bd = sd = i;
            }
        }
        vector<int> vec;
        vec.push_back(bd);
        vec.push_back(sd);
        v.push_back(vec);
        profit+=A[sd] - A[bd];

        // print(v);
        if(profit==0){
            v.clear();
            return v;
        }
        return v;
    }
};