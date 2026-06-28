class Solution {
  public:
    bool solve(string &s, int left, int right) {
        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return solve(s, left + 1, right - 1);
    }

    bool isPalindrome(string& s) {
        return solve(s, 0, s.length() - 1);
    }
};