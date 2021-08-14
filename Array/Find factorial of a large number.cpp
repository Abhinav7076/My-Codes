//more efficient way is to use linked lst coz it adds nums dynamically
class Solution {
public:
    struct Node
    {
        int data;
        Node* prev;
        
        Node(int val)
        {
            data = val;
            prev = NULL;
        }
    };
    
    void multiply(Node* tail, int n){
        Node *prevNode = tail, *temp = tail;  //prevnode : ek node peeche rehne k liye
        int carry=0;
        while(temp != NULL){
            int data = temp->data*n+carry;
            temp->data = data%10;
            carry = data/10;
            prevNode = temp;
            temp = temp->prev;
        }
        while(carry!=0){
            prevNode->prev = new Node(carry%10);
            carry = carry/10;
            prevNode = prevNode->prev;
        }
        return;
    }
    
    vector<int> factorial(int n){
        // code here
        int num = 1;
        Node* tail = new Node(1);
        for(int i=2;i<=n;i++){
            multiply(tail, i);
        }
        vector<int> v;
        while(tail!=NULL){
            v.push_back(tail->data);
            // cout<<tail->data;
            tail=tail->prev;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//array approach
class Solution {
public:
    vector<int> factorial(int n){
        // code here
        int q=2;
    int arr[100000] = {0};
    arr[0] = 1;
    int len = 1;
    int x = 0;
    int num = 0;
    while(q<=n)
    {
        x=0;
        num =0;
        while(x<len)
        {
            arr[x] = arr[x] *q;
            arr[x] = arr[x]+num;
            num = arr[x]/10;
            arr[x] = arr[x]%10;
            x++;
        }
        while(num!=0)
        {
            arr[len] = num%10;
            num = num/10;
            len++;
        }
        q++;
    }
    len--;
    vector<int> ans;
    while(len>=0)
    {
        ans.push_back(arr[len]);
        // cout<<arr[len];
        len = len-1;
    }
    return ans;
    }
};