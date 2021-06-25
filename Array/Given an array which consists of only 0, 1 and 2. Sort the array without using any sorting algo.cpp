void sort012(int a[], int n)
    {
        // coode here
        int count[3]={0};
        
        
        for(int i=0;i<n;i++){
            count[a[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<count[i];j++)
            a[index++]=i;
        }
        
        
    }