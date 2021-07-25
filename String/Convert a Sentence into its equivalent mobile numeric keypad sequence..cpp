void fillMap(unordered_map<char,string> &u){
    u[' '] = '0';
    u['A'] = "2";
    u['B'] = "22";
    u['C'] = "222";
    u['D'] = "3";
    u['E'] = "33";
    u['F'] = "333";
    u['G'] = "4";
    u['H'] = "44";
    u['I'] = "444";
    u['J'] = "5";
    u['K'] = "55";
    u['L'] = "555";
    u['M'] = "6";
    u['N'] = "66";
    u['O'] = "666";
    u['P'] = "7";
    u['Q'] = "77";
    u['R'] = "777";
    u['S'] = "7777";
    u['T'] = "8";
    u['U'] = "88";
    u['V'] = "888";
    u['W'] = "9";
    u['X'] = "99";
    u['Y'] = "999";
    u['Z'] = "9999";
}

string printSequence(string s)
{
    //code here.
    unordered_map<char,string> u;
    fillMap(u);
    string ans="";
    for(int i=0;i<s.length();i++){
        ans+=u[s[i]];
    }
    return ans;
    
}