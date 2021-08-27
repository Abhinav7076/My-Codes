long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int b[n];
    vector<long long int> v;
    int i=0,front=0,back=n-1;
    for(i=0;i+1<n;i=i+2){
        b[i] = arr[front++];
        b[i+1] = arr[back--];
    } 
    if(n%2==1)
    b[i] = arr[front];
    long long int sum=0;
    for(int i=1;i<n;i++){
        sum=sum+abs(b[i]-b[i-1]);
    }
    sum=sum+abs(b[n-1]-b[0]);
    return sum;
    
}