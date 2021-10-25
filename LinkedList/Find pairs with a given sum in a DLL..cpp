// Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
//         x = 7
// Output: (6, 1), (5,2)

// Function to find pair whose sum equal to given value x.
void pairSum(struct Node *head, int x)
{
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;
 
    // To track if we find a pair or not
    bool found = false;
 
    // The loop terminates when two pointers
    // cross each other (second->next
    // == first), or they become same (first == second)
    while (first != second && second->next != first)
    {
        // pair found
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;
 
            // move first in forward direction
            first = first->next;
 
            // move second in backward direction
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
 
    // if pair is not present
    if (found == false)
        cout << "No pair found";
}