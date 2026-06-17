class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=nums[0];
        int mn=nums[0];
        int ans=max(abs(mx), abs(mn));;
        for(int i=1;i<nums.size();i++){
            mx=max(mx+nums[i],nums[i]);
            mn=min(mn+nums[i],nums[i]);

            ans=max(ans,max(abs(mx),abs(mn)));
        }
        return ans;
    }
};