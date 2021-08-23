#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
        
        for(int i=0,l=v.size()-1;i<v.size()/2;i++,l--){
            if(v[i]!=v[l])
            return false;
        }
        return true;
    }
};