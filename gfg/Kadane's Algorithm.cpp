class Solution {
  public:
    int maxSubarraySum(vector<int> &nums) {
        // Code here
        int best=nums[0];
        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            best=max(v1,nums[i]);
            ans=max(ans,best);
        }
        return ans;
    }
};