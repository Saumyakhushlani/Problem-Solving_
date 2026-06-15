class Solution {
public:
    int solve(vector<int>& nums, int t, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(t + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][t];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int k = sum + target;
        if (sum + target < 0 || (sum + target) % 2)
            return 0;
        return solve(nums, k / 2, nums.size());
    }
};