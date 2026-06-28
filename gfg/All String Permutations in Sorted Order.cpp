class Solution {
  public:
    void solve(string &s, vector<string> &res, string &tmp) {
        if (s.empty()) {
            res.push_back(tmp);
            return;
        }

        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            tmp.push_back(ch);
            s.erase(s.begin() + i);

            solve(s, res, tmp);

            s.insert(s.begin() + i, ch);
            tmp.pop_back();
        }
    }

    vector<string> permutation(string s) {
        vector<string> res;
        string tmp;
        solve(s, res, tmp);
        sort(res.begin(), res.end()); 
        return res;
    }
};