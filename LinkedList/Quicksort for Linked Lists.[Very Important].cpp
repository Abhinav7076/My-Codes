#include<bits/stdc++.h>
node* rev(node* head){
    node* nex;
    node* prev = NULL;
    node* cur = head;
    while(cur != NULL){
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    return prev;
}

void quickSort(struct node **headRef) {
    node *cur = *headRef;
    vector<int> v;
    while(cur != NULL){
        v.push_back(cur->data);
        cur = cur->next;
    }
    sort(v.begin(), v.end());
    node* head = new node(v[0]);
    node* head_copy = head;
    for(int i=1;i<v.size();i++){
        head->next = new node(v[i]);
        head = head->next;
    }
    *headRef = head_copy;
}