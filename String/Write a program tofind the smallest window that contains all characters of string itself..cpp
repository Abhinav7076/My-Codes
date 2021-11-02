// acuire and release tactic
class Solution{
    public:
    int countWords(string s){
        int n =s.length();
        unordered_map<char,int> u;
        for(int i=0;i<n;i++){
            u[s[i]]++;
        }
        return u.size();
    }
    
    string findSubString(string s)
    {
        // Your code goes here
        int nos = countWords(s);
        int i=-1,j=-1,n=s.length();
        int ma = n;
        string ans = s;
        unordered_map<char,int> u;
        while(1){
            //acquire till map size  == nos
            bool f1=false, f2= false;
            
            while(i<n-1 and u.size() < nos){
                i++;
                u[s[i]]++;
                f1=true;
            }
            //collect and release
            while(j<i and u.size() == nos){
                int len = i - j;
                if(len < ma){
                    ma = len;
                    ans = string(s.begin()+j+1 , s.begin() + i +1 );
                }
                
                j++;
                if(u[s[j]] == 1)
                u.erase(s[j]);
                else
                u[s[j]]--;
                f2=true;
            }
            
            if(!f1 and !f2)
            break;
        }
        // cout<<ans<<" "<<ma<<endl;
        return ans;
        
        
    }
};