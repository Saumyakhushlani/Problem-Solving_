class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
         sort(nums.begin(), nums.end());

        int end1 = nums[0][1];
        int res = 0;

        for (int i = 1; i < nums.size(); i++) {
            int start2 = nums[i][0];
            int end2 = nums[i][1];

            if (start2 < end1) {
                res++;                 
                end1 = min(end1, end2);
            } else {
                end1 = end2;
            }
        }

        return res;
    }
};