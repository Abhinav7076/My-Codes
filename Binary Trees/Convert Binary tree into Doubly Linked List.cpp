class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node *root,Node *&head,Node *&pre,int &f)
    {
        if(!root) return;
        solve(root->left,head,pre,f);
        if(f==0)
        {
            f=1;
            head=root;
            pre=root;
        }
        else
        {
            pre->right=root;
            pre->right->left=pre;
            pre=pre->right;
        }
        solve(root->right,head,pre,f);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node *head=nullptr;
        Node *pre=nullptr;
        int f=0;
        solve(root,head,pre,f);
        return head;
    }
};
