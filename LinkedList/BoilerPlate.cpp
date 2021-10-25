#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        vector<int> v;
        Node* prev = NULL;
        Node* nex;
        Node* cur = head;
        while(cur!=NULL){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node* rev = reverseList(head);
        int ma = INT_MIN;
        Node* cur = NULL, *start;
        while(rev!=NULL){
            if(rev->data >= ma){
                if(cur == NULL){
                    cur = new Node(rev->data);
                    start = cur;
                }
                else{
                    cur->next = rev;
                    cur = cur->next;
                }
                ma = rev->data;
            }
            rev = rev->next;
        }
        cur->next = NULL;
        return reverseList(start);
        
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends