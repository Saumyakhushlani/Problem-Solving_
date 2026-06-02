class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -1 * nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> a = {nums[i], nums[left], nums[right]};
                    res.push_back(a);
                    left++;
                    right--;
                    while (left < nums.size() && nums[left] == nums[left - 1])
                        left++;
                    while (right < nums.size() &&
                           nums[right] == nums[right + 1])
                        right--;
                } else if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                }
            }
        }

        return res;
    }
};