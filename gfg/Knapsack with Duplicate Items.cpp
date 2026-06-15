class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt, int c,int n){
        vector<vector<int>> dp(n+1, vector<int>(c+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=c;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else{
                    if(j>=wt[i-1]){
                        dp[i][j]=max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][c];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        return solve(val,wt,capacity,val.size());
        
    }
};