int minFlips (string S)
{
    // your code here
    int count=0,count2=0;
    
    for(int i=0;i<S.length();i++){
        if(i%2==0 and S[i]=='0'){
            count++;
        }
        else if(i%2==1 and S[i]=='1'){
            count++;
        }
    }
   for(int i=0;i<S.length();i++){
        if(i%2==0 and S[i]=='1'){
            count2++;
        }
        else if(i%2==1 and S[i]=='0'){
            count2++;
        }
    }
    return min(count, count2);
}