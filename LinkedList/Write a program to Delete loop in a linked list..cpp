#include <bits/stdc++.h>
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL or head->next==NULL)
        return;
        unordered_map<Node*, int> m;
        Node* prev;
        Node* cur;
        prev = head;
        cur = head->next;
        m[prev] = 1;
        while(cur!=NULL and prev!=NULL){
            if(!m[cur]){
                m[cur] = 1;
                prev = prev->next;
                cur = cur->next;
            }
            else{
                        prev->next = NULL;
                break;
            }
            
        }

    }
};

// In fact, you can get a tighter bound on the step count if you note that when there's a loop, the slow pointer will get to it in N - M steps, so the total step count is <= N.