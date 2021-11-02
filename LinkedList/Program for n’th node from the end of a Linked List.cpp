//method 1 :
int findLen(struct Node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

int getNthFromLast(struct Node *head, int n)
{
    int len = findLen(head);
    if(n > len)
    return -1;
    for(int i=1;i<=len-n;i++)
    head = head->next;
    return head->data;
}

//method 2 : recursive
void printNthFromLast(struct Node* head, int n)
{
    int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, n);
    if (++i == n)
        cout<<head->data;
}



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
