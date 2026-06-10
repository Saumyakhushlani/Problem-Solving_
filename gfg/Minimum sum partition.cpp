class Solution {
  public:
  int solve(vector<int>& arr, int s) {
        vector<bool> dp(s + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = s; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int mn = INT_MAX;

        for (int i = 0; i <= s; i++) {
            if (dp[i]) {
                mn = min(mn, abs(s - 2 * i));
            }
        }

        return mn;
    }
    int minDifference(vector<int>& arr) {
        // code here
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }
        return solve(arr, sum);
    }
};
