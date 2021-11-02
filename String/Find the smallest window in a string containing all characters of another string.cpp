// acuire and release tactic
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int>mp1,mp2;
       int start =0;
       for(int i=0;i<p.length();i++)
         mp1[p[i]]++;
         
         int des_count = p.length();
         int count1=0;
         
         int i=0,j=0;
         int res = INT_MAX;
         while(i<=j and j < s.length())
         {
             if(count1<des_count)
             {
                 mp2[s[j]]++;
                 if(mp2[s[j]] <= mp1[s[j]])
                    count1++;
                    j++;
             }
             else if(count1 == des_count)
             {
                  if(res!=j-i and res>j-i){
               //   res = min(res,j-i);
               res =j-i;
                 start =i;
                 }
                  mp2[s[i]]--;
                 if(mp2[s[i]]<mp1[s[i]] and mp2[s[i]]>=0)
                   count1--;
                  
                   i++;
             }
         }
       while(count1 == des_count)
       {        
                 if(res!=j-i and res>j-i){
               //   res = min(res,j-i);
               res =j-i;
                 start =i;
                 }
                  mp2[s[i]]--;
                 if(mp2[s[i]]<mp1[s[i]] and mp2[s[i]]>=0)
                   count1--;
                  
                   i++;
       }
       
       return res!=INT_MAX?s.substr(start,res):"-1";
    }
};