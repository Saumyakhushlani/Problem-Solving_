class Solution {
public:
    void solve(string d,int idx, string tmp, vector<string>& res, unordered_map<char, string>& mpp){
        if(idx==d.size()){
            res.push_back(tmp);
            return;
        }
        string choice = mpp[d[idx]];
        for(char j:choice){
            tmp.push_back(j);
            solve(d, idx+1,tmp,res,mpp);
            tmp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string> res;
        string tmp="";
        solve(digits,0,tmp,res,mpp);
        return res;
    }
};