// string banayenge, null pe delimeter return karenge 
// aur map me string ki frequency store karte jayenge
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string, int> u;
    string solve(Node* root){
        if(!root)
        return "$";
        string s="";
        if(!root->left and !root->right){
            s = to_string(root->data);
            return s;
        }
        s = s + to_string(root->data);
        s = s + solve(root->left);
        s = s + solve(root->right);
        u[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
         u.clear();
         solve(root);
         for(auto x:u){
             if(x.second>=2)
                return true;
         }
         return false;
    }
};