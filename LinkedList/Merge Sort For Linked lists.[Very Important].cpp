// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void MergeSort(Node** head){
        Node* cur = *head;
        Node* first, *second;
        if(!cur or !cur->next)
        return;
        
        findMiddle(cur, &first, &second);
        
        MergeSort(&first);
        MergeSort(&second);
        *head = MergeBoth(first, second);
    }
    Node* MergeBoth(Node* first, Node* second){
        Node* ans = NULL;
        if(!first)
        return second;
        
        if(!second)
        return first;
        
        if(first->data <= second->data){
            ans = first;
            ans->next = MergeBoth(first->next, second);
        }
        else{
            ans = second;
            ans->next = MergeBoth(first, second->next);
        }
        return ans;
    }
    void findMiddle(Node* cur, Node** first, Node** second){
        Node* slow = cur;
        Node* fast = cur->next;
        
        while(fast!=NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *first = cur;
        *second = slow->next;
        slow->next = NULL;
    }
    Node* mergeSort(Node* head) {
        // your code here
        MergeSort(&head);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
//other

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
    vector<int> v;
    while(head!=NULL){
        v.push_back(head->data);
        head = head->next;
    }
    sort(v.begin(), v.end());

    if(v.size()>0){
    Node* head = new Node(v[0]);
    //return head;
    Node* head_copy = head;
    for(int i=1;i<v.size();i++){
        head->next = new Node(v[i]);
        head = head->next;
    }
    return head_copy;
    }
    else return NULL;
    }
};