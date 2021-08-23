class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int l=0;
        ListNode* head_copy = head;
        while(head!=NULL){
        l++;
        head = head->next;
        }
        for(int i=0;i<l/2;i++)
            head_copy = head_copy->next;
        return head_copy;

    }
};