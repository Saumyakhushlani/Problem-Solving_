class Solution {
  public:
    bool isIntersect(vector<vector<int>> nums) {
        // Code Here
        sort(nums.begin(), nums.end());

        int end1 = nums[0][1];

        for (int i = 1; i < nums.size(); i++) {
            int start2 = nums[i][0];
            int end2 = nums[i][1];

            if (start2 <= end1) {
                return true;         
            } else {
                end1 = end2;
            }
        }

        return false;
    }
};