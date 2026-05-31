class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        vector<int>dp(n+1,-1);
        dp[1]=k;
        dp[2]=k*k;
        
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-2]*(k-1))+(dp[i-1]*(k-1));
        }
        return dp[n];
    }
};