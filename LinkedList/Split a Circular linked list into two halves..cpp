void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head;
    Node *fast = head->next;
    while(fast != head and fast->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    //slow is the middle element
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    Node* cur = *head2_ref;
    while(cur->next != head){
        cur = cur->next;
    }
    cur->next = *head2_ref;
}