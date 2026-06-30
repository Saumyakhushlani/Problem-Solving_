class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
         unordered_map<char, int> mpp;
        int low = 0;
        int high = 0;
        int cnt = 0;

        while (high < s.size()) {
            mpp[s[high]]++;

            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                cnt += s.size() - high;
                mpp[s[low]]--;
                low++;
            }

            high++;
        }

        return cnt;
    }
};