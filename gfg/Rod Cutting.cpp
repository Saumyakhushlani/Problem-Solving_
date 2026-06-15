class Solution {
public:
    int solve(vector<int>& val, vector<int>& wt, int c, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= c; j++) {
                if (j >= wt[i - 1]) {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - wt[i - 1]] + val[i - 1]
                    );
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][c];
    }

    int cutRod(vector<int>& price) {
        int n = price.size();

        vector<int> wt(n);
        for (int i = 0; i < n; i++) {
            wt[i] = i + 1; 
        }

        return solve(price, wt, n, n);
    }
};