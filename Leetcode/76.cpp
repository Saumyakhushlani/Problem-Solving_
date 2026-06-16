class Solution {
public:
    bool solve(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> a(128, 0);
        vector<int> b(128, 0);
        for (int i = 0; i < t.size(); i++) {
            b[t[i]]++;
        }
        int low = 0;
        int high = 0;
        int start = -1;
        int len = INT_MAX;

        while (high < s.size()) {
            a[s[high]]++;
            while (solve(a, b)) {
                if (high - low + 1 < len) {
                    len = high - low + 1;
                    start = low;
                }
                a[s[low]]--;
                low++;
            }
            high++;
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};