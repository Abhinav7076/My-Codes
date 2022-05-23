// The idea is to consider every character as a starting character and find all words starting with it. All words starting from a character can be found using Depth First Traversal. We do depth-first traversal starting from every cell. We keep track of visited cells to make sure that a cell is considered only once in a word.

class Solution {
public:
    
    vector<pair<int,int>> p={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
   bool func(vector<vector<char>> &v,int i,int j,string &word,int k){
       if(k==word.size()) return true;
       if(i<0 or j<0 or i==v.size() or j==v[0].size() or v[i][j]!=word[k]) return false;
       char ch=v[i][j];
       v[i][j]='.';
       for(auto l:p) if(func(v,i+l.first,j+l.second,word,k+1)){
           v[i][j]=ch;
           return true;
       }
       v[i][j]=ch;
       return false;
   }
   bool isWordExist(vector<vector<char>>& v, string &word) {
       int m=v.size(),n=v[0].size();
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++) if(func(v,i,j,word,0)) return true;
       }
       return false;
   }
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dic) {
        // Code here
        vector<string> ans;
        for(auto i: dic) if(isWordExist(board,i)) ans.push_back(i);
        return ans;
    }
};