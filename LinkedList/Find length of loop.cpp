int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head == NULL or head->next == NULL)
    return 0;
    unordered_map<Node*, int> u;
    int c=1;
    Node* cur = head->next;
    Node* prev = head;
    u[prev] = c++;
    while(cur!=NULL){
        if(!u[cur]){
            u[cur] = c++;
            prev=prev->next;
            cur=cur->next;
        }
        else{
            return u[prev] - u[cur] + 1;
        }
    }
    return 0;
}