class Solution{   
public:
    string doSum(string a, string b)
    {
        if(a.size() < b.size())
            swap(a, b);
    
        int j = a.size()-1;
        for(int i=b.size()-1; i>=0; i--, j--)
            a[j]+=(b[i]-'0');
    
        for(int i=a.size()-1; i>0; i--)
        {
            if(a[i] > '9')
            {
                int d = a[i]-'0';
                a[i-1] = ((a[i-1]-'0') + d/10) + '0';
                a[i] = (d%10)+'0';
            }
        }
        if(a[0] > '9')
        {
            string k;
            k+=a[0];
            a[0] = ((a[0]-'0')%10)+'0';
            k[0] = ((k[0]-'0')/10)+'0';
            a = k+a;
        }
        return a;
    }
        
    string trimZeros(string s){
        int index=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                index = i;
                break;
            }
        }
        if(index!=-1)
        return string(s.begin()+index, s.end());
        else
        return "";
    }
    string solve(int arr[], int n) {
        // code heres
        sort(arr,arr+n);
        string s0="";
        string s1="";
        queue<int> q;
        for(int i=0;i<n;i++)
            q.push(arr[i]);
        
        bool f=false;
        while(!q.empty()){
            if(f==false){
                s0=s0+to_string(q.front());
                q.pop();
                f=!f;
            }
            else{
                s1=s1+to_string(q.front());
                q.pop();
                f=!f;
            }
        }
        // cout<<s0<<" "<<s1<<endl;
        return trimZeros(doSum(s0,s1));   
    }
};