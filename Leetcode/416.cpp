class Solution {
public:
    bool solveTab(vector<int>& arr, int s, int n){
        vector<vector<int>>dp (n+1,vector<int>(s+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(i==0||s==0){
                    dp[i][j]=0;
                }
                else if(j>=arr[i-1]){
                    dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i-1][j-arr[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s]==s;
    }

    int solve(vector<int>& arr, int s){
        vector<bool> dp(s+1,false);
        dp[0]=true;
        for(int num:arr){
            for(int j=s;j>=num;j--){
                dp[j]=dp[j]||dp[j-num];
            }
        }
        return dp[s];
    }
    bool canPartition(vector<int>& nums) {
        int ts = 0;
        for (int num : nums) ts += num;

        if (ts % 2 != 0) return false;

        int s = ts / 2;
        // return solveTab(nums,s,nums.size());
        return solve(nums,s);
    }
};