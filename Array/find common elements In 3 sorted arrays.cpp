class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector <int> v;
            set<int> s;
            unordered_map<int,int> m;
            for(int i=0;i<n1;i++){
                m[A[i]]=1;
            }
            for(int i=0;i<n2;i++){
                if(m[B[i]]==1)
                m[B[i]]=2;
            }
           for(int i=0;i<n3;i++){
                if(m[C[i]]==2)
                s.insert(C[i]);
            }
            set<int>::iterator it;
            for( it=s.begin();it!=s.end();it++)
            v.push_back(*it);
            return v;
            
        }

};