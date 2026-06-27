class Solution {
public:
    void solve(vector<int>& digits, int idx, string& tmp,
               vector<string>& res,
               unordered_map<int, string>& mpp) {

        if (idx == digits.size()) {
            res.push_back(tmp);
            return;
        }

        string choice = mpp[digits[idx]];

        for (char ch : choice) {
            tmp.push_back(ch);
            solve(digits, idx + 1, tmp, res, mpp);
            tmp.pop_back();
        }
    }

    vector<string> possibleWords(vector<int>& digits) {

        if (digits.empty()) return {};

        unordered_map<int, string> mpp;

        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        vector<string> res;
        string tmp = "";

        solve(digits, 0, tmp, res, mpp);

        return res;
    }
};