// take a height ma and store the height of first leaf and then check if 
// the height of another leaf nofe is not equal to ma thne retyrn false
class Solution{
  public:
    /*You are required to complete this method*/
    int ans,ma;
    
    void solve(Node* root, int h){
        if(!root) return;
        if(ans==0) return;
        if(!root->left and !root->right){
            if(ma==-1)
            ma = h;
            else{
                if(h!=ma){
                    ans = 0;
                }
            }
            return;
        }
        
        solve(root->left,h+1);
        solve(root->right,h+1);

    }
    
    bool check(Node *root)
    {
        //Your code here
        ma= -1 ;
        ans = 1;
        int h = 0;
        solve(root,h);
        return ans;
    }
};