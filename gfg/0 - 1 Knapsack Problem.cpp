class Solution {
  public:
    int fun(int i, int W,vector<int>& val,vector<int> &wt,vector<vector<int>>& dp){
        int n = val.size();
        if(i==n)return 0;
        if(dp[W][i]!=-1)return dp[W][i];
        if(W<wt[i]){
            return dp[W][i]= fun(i+1,W,val,wt,dp);
        }
        int inc = val[i]+fun(i+1,W-wt[i],val,wt,dp);
        int exc= fun(i+1,W,val,wt,dp);
        return dp[W][i]= max(inc,exc);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(W+1,vector<int>(n,-1));
        return fun(0,W,val,wt,dp);
    }
};