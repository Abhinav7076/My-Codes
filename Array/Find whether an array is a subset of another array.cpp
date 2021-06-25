string isSubset(int a1[], int a2[], int n, int m) {
    int present[100001]={0};
    for(int i=0;i<n;i++)
    present[a1[i]]=1;
    
    int c=0;
    for(int i=0;i<m;i++){
        if(present[a2[i]]==1)
        c++;
    }
    
    if(c==m)
    return "Yes";
    else
    return "No";
}