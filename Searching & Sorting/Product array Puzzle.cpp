vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here        
    vector<long long int> v;
    
    int f=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
        f++;
    }
    
    if(f==1){
    long long int p=1;
    for(int i=0;i<n;i++){
        if(nums[i]!=0)
            p=p*nums[i];
    }
    
    for(int i=0;i<n;i++){
        if(nums[i]==0)
        v.push_back(p);
        else
        v.push_back(0);
        }
    }
    else if(f==0){
    
    long long int p=1;
    for(int i=0;i<n;i++)
    p=p*nums[i];
    
    for(int i=0;i<n;i++){
        v.push_back(p/nums[i]);
    }
    }
    else{
        for(int i=0;i<n;i++)
        v.push_back(0);
    }
    return v;
}