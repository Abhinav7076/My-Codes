class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> u;
        for(int i=0;i<n;i++){
            u[arr[i]]++;
        }
        unordered_map<string, int>::iterator it;
        int ma=0,m2=0;
        string str="";
        for(it=u.begin();it!=u.end();it++){
            if(it->second>ma){
            ma=it->second;
            str=it->first;
            }
        }
        ma=0;
        u[str]=0;
        for(it=u.begin();it!=u.end();it++){
            if(it->second>ma){
            ma=it->second;
            str=it->first;
            }
        }
        return str;
    }
};