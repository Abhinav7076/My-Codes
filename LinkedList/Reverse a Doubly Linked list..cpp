Node* reverseDLL(Node * head)
{
    //Your code here
    if(head->prev == NULL and head->next == NULL)
    return head;
    
    while(head->next!=NULL){
        head = head->next;
    }
    
    Node* cur = head;
    cur->next = cur->prev;
    cur->prev = NULL;
    cur = cur->next;
    
    while(cur->prev!=NULL){
        Node* temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->next;
    }
    cur->prev = cur->next;
    cur->next = NULL;
    
    return head;
}
