
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v={-1,-1};
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            v[0]=i;
            //cout<<i<<" ";
            break;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(arr[i]==x){
            v[1]=i;
            //cout<<i<<" ";
            break;
        }
    }
    return v;

}