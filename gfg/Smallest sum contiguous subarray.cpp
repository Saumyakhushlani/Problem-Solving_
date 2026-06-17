// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& nums) {
        // Code here
        int best=nums[0];
        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            best=min(v1,nums[i]);
            ans=min(ans,best);
        }
        return ans;
    }
};
