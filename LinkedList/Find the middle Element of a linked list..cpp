class Solution {
public:
    int findLen(ListNode* head){
        int l=0;
        while(head!=NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        if(findLen(head)%2 == 0)
        return slow->next;
        return slow;
    }
};

//method 2
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