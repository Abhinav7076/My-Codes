/* Takes two lists sorted in increasing order, and merge
   their nodes together to make one big sorted list. Below
   function takes O(n) extra space for recursive calls,
    */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
 
// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;
 
        // (i, j) forms a pair
        while (i < j) {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = SortedMerge(arr[i], arr[j]);
 
            // consider next pair
            i++, j--;
 
            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }
 
    return arr[0];
}

//other
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
            Node* ans;
            Node* head;
            vector<int> v;
            
            for(int i=0;i<K;i++){
                Node* head = arr[i];
                while(head!=NULL){
                    v.push_back(head->data);
                    head=head->next;
                }
            }
            sort(v.begin(), v.end());
            
            ans = new Node(v[0]);
            head = ans;
            for(int i=1;i<v.size();i++){
                ans->next = new Node(v[i]);
                ans=ans->next;
            }
            ans->next=NULL;
            return head;
    }
};
