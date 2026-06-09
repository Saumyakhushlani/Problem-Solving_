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
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return solveTab(arr,sum,arr.size());
    }
};

