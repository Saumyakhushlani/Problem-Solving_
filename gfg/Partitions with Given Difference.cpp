class Solution {
  public:
    int solve(vector<int> &arr, int t, int n) {
		vector<vector<int>> dp(n + 1, vector<int>(t + 1));
		dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {

                dp[i][j] = dp[i - 1][j];
                
                if (arr[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
                }
            }
        }
		return dp[n][t];
	}
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum =0;
        for(int num:arr){
            sum+=num;
        }
         if (sum < diff) return 0;
        if ((sum + diff) % 2) return 0;

        int target = (sum + diff) / 2;

        return solve(arr, target, arr.size());
    }
};