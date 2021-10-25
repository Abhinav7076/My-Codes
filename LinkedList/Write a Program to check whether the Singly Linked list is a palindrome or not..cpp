bool isPalin(Node* head){
         
        // Temp pointer
        Node* slow= head;
 
        // Declare a stack
        stack <int> s;
  
 
        // Push all elements of the list
        // to the stack
        while(slow != NULL){
                s.push(slow->data);
 
                // Move ahead
                slow = slow->ptr;
        }
 
        // Iterate in the list again and
        // check by popping from the stack
        while(head != NULL ){
             
            // Get the top most element
             int i=s.top();
 
             // Pop the element
             s.pop();
 
             // Check if data is not
             // same as popped element
            if(head -> data != i){
                return false;
            }
 
            // Move ahead
           head=head->next;
        }
 
return true;
}

//other method


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