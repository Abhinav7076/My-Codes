#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    public:
    
        int minEle;
        stack<int> s;
        stack<int>min;
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()==true){
               return -1;
           }
           return (min.top());
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()==true){
               return -1;
           }
           int k=s.top();
           s.pop();
           if(k==min.top()){
              
              min.pop();
           }
           return k;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
            //Write your code here
           s.push(x);
           if(min.empty()==true){
               min.push(x);
           }
           else if(x<=min.top()){
               min.push(x);
           }
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends