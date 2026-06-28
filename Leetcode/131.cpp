class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
    void solve(string s, vector<vector<string>>& res, vector<string> tmp,
                int idx) {
        if (idx == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int end = idx + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, idx, end - 1)) {
                tmp.push_back(s.substr(idx, end - idx));
                solve(s, res, tmp, end);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> tmp;
        solve(s,res,tmp,0);
        return res;
    }
};