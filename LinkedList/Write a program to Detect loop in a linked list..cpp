class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL)
        return false;
        unordered_map<Node*, int> m;
        while(head!=NULL){
            if(!m[head]){
                m[head] = 1;
                head= head->next;
            }
            else
            return true;
            
        }
        
        return false;
    }
};

//hare and tortoise approach
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node* low = head;
        Node* high = head;
        while(high!=NULL and high->next!=NULL){
            low = low->next;
            high = high->next->next;
            if(low == high){
                return true;
            }
        }
        return false;
    }
};