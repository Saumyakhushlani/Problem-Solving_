class Solution {
public:
    int solveMem(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) {
            return 1;
        }
        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];
        int ans = 0;
        for (int num : nums) {
            ans += solveMem(nums, target - num, dp);
        }
        dp[target] = ans;
        return dp[target];
    }

    int solveTab(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1,-1);
        // return solveMem(nums,target, dp);

        return solveTab(nums, target);
    }
};