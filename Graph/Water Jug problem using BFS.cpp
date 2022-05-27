int minSteps(int m, int n, int d)
{
    int c1=m,c2=0,cnt=1,cnt2=1;
    if(d>m and d>n)
    return -1;
    map<pair<int,int>,int>mp;

//CASE1:always  pour water from jug 1 to jug2 if at any stage jug1 become empty fill it again or if jug2 fill fully empty it again until one of the jug have d litre of water
    while(c1!=d and c2!=d)
    {
        mp[{c1,c2}]++;
        int remain=n-c2;
        if(remain>=c1)
        {
            
        cnt++;
        c2+=c1;
        c1=0;
        }
        else
       {
           c2+=remain;
           c1-=remain;
            cnt++;
       }

//if at any stage c1 or c2 become equals to d then break the loop 
       if(c1==d||c2==d)
       break;
        if(c1==0)
        {
        c1=m;
        cnt++;
        }
        if(c2==n)
        {
        c2=0;
        cnt++;
        }

//if at any stage same procedure starts following  again then break the loop 
       if(mp.find({c1,c2})!=mp.end())
       {
           cnt=-1;
           break;
       }
        
    }

//CASE2:always  pour water from jug 2  to jug1 if at any stage jug2 become empty fill it again or if jug1 fill fully empty it again until one of the jug have d litre of water
    mp.clear();
    c1=0;
    c2=n;
       while(c1!=d and c2!=d)
    {
          mp[{c1,c2}]++;
        int remain=m-c1;
        if(remain>=c2)
        {
            
        cnt2++;
        c1+=c2;;
        c2=0;
        }
        else
       {
           cnt2++;
           c1+=remain;
           c2-=remain;
       }

//if at any stage c1 or c2 become equals to d then break the loop 
         if(c1==d||c2==d)
       break;
        if(c1==m)
        {
        c1=0;
        cnt2++;
        }
        if(c2==0)
        {
        c2=n;
        cnt2++;
        }

 

//if at any stage same procedure starts following  again then break the loop 
         if(mp.find({c1,c2})!=mp.end())
       {
           cnt2=-1;
           break;
       }
        
    }
    if(cnt==-1 and cnt2==-1)return -1;
    if(cnt==-1)return cnt2;
    if(cnt2==-1)return cnt;
    return min(cnt,cnt2);
    
}