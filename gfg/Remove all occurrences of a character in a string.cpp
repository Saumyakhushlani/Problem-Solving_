class Solution {
  public:
    // Function to remove all occurrences of the character from the string
    void solve(string &s,char c,int idx,string &res){
        if(idx==s.size()){
            return;
        }
        if(s[idx]==c){
            solve(s,c,idx+1,res);
        }else{
            res.push_back(s[idx]);
            solve(s,c,idx+1,res);
        }
        
    }
    void removeCharacter(string &s, char c) {
        // code here
        string res;
        solve(s,c,0,res);
        s=res;
        
    }
};