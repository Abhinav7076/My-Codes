// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = head;
 
    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}

//other
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
    vector<int> v;
        while(head!=NULL){
            v.push_back(head->data);
            head = head->next;
        }
    
    sort(v.begin(), v.end());
    Node* head2 = new Node(v[0]);
    //return head2;
    Node* head_copy = head2;
    for(int i=1;i<v.size();i++){
        head2->next = new Node(v[i]);
        head2 = head2->next;
    }
    return head_copy;   
    }
};