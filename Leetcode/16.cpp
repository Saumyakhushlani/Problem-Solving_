class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int curr = nums[i] + nums[left] + nums[right];

                if (abs(curr - target) < abs(res - target))
                    res = curr;

                if (curr == target)
                    return curr;
                else if (curr > target)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};