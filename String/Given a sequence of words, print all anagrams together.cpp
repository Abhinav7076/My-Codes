bool isAnagram(string s1, string s2){
    unordered_map<char,int> u;
    if(s1.length()!=s2.length())
    return false;
    for(int i=0;i<s1.length();i++){
        u[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        u[s2[i]]--;
    }
    unordered_map<char,int>::iterator it;
    for(it=u.begin();it!=u.end();it++){
        if((it->second)!=0)
        return false;
    }
    return true;
}

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    int n = string_list.size();
    vector<vector<string> > v;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<string> ana;
            ana.push_back(string_list[i]);
            for(int j=i+1;j<n;j++){
                if(!visited[j] and isAnagram(string_list[i], string_list[j])){
                visited[j] = true;
                ana.push_back(string_list[j]);
                }
            }
            v.push_back(ana);
        }
    }
    return v;
}