class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int oneDel=0;
        int ans =nums[0];
        int noDel=nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int prevNoDel = noDel;
            int prevOneDel = oneDel;

            oneDel = max(prevNoDel, prevOneDel + nums[i]);
            noDel = max(prevNoDel + nums[i], nums[i]);

            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};