class Solution {
public:
    void solve(int n,int o,int c,string tmp,vector<string>& res){
        if(o==n && c==n){
            res.push_back(tmp);
            return;
        }
        if(o<n){
            tmp.push_back('(');
            solve(n,o+1,c,tmp,res);
            tmp.pop_back();
        }
        if(c<o){
            tmp.push_back(')');
            solve(n,o,c+1,tmp,res);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        solve(n,0,0,tmp,res);
        return res;
    }
};