class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];
        int ans =nums[0];
        int mn=nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int v1 = mx * nums[i];
            int v2 = mn * nums[i];

            mx = max(nums[i], max(v1, v2));
            mn = min(nums[i], min(v1, v2));
            ans=max(ans,mx);
        }
        return ans;
    }
};