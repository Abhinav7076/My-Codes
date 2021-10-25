// Algorithm: 
// …1) Get pointer to the last node. 
// …2) Move all the odd nodes to the end. 
// ……..a) Consider all odd nodes before the first even node and move them to end. 
// ……..b) Change the head pointer to point to the first even node. 
// ……..b) Consider all odd nodes after the first even node and move them to the end. 
// Method 1
void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
 
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;
 
    /* Consider all odd nodes before the first
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        *head_ref = curr;
 
        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing
    lines following this statement */
    else prev = curr;
 
    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

//method 2
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *even = NULL, *se;
        Node *odd = NULL, *so;
        while(head != NULL){
            if(head->data%2==0){
                if(even == NULL){
                    even = new Node(head->data);
                    se = even;
                }
                else{
                    even->next = head;
                    even = even->next;
                }
            }
            else{
                if(odd == NULL){
                    odd = new Node(head->data);
                    so = odd;
                }
                else{
                    odd->next = head;
                    odd = odd->next;
                }
            }
            head = head->next;
        }
        if(even == NULL)
        return so;
        else if(odd == NULL)
        return se;
        odd->next = NULL;
        even->next = so;
        return se;
    }
};


class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
        
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<v.size();i++){
            if(v[i]%2==1)
            odd.push_back(v[i]);
            else
            even.push_back(v[i]);
        }
        for(int i=0;i<even.size();i++){
            v[i] = even[i];
        }
        for(int i=0;i<odd.size();i++){
            v[i+even.size()] = odd[i];
        }

        
        if(v.size()>0){
    Node* head2 = new Node(v[0]);
    //return head;
    Node* head_copy = head2;
    for(int i=1;i<v.size();i++){
        head2->next = new Node(v[i]);
        head2 = head2->next;
    }
    return head_copy;
    }
    else return NULL;
    }
};
