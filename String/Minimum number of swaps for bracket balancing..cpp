class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here
        vector<int> v;
        for(int i=0;i<S.length();i++){
            if(S[i]=='[')
            v.push_back(i);
        }
        int count=0,index=0,total=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='['){
            count++;
            index++;
            }
            else{
                count--;
                if(count<0){
                    total=total+v[index]-i;
                    swap(S[i], S[v[index]]);
                    index++;
                    count=1;
                    
                    }
                }
            }
            return total;
    }
};