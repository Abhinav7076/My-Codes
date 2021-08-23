#include<bits/stdc++.h>
int getNthFromLast(Node *head, int n)
{
       // Your code here
       vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
        if(n<=v.size())
        return v[v.size()-n];
        else return -1;
}
