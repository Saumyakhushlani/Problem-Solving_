class Solution {
  public:
    int smallestSubWithSum(int target, vector<int>& nums) {
        // Your code goes here
        int ans = INT_MAX;
        int low = 0;
        int high = 0;
        int sum = 0;
        while (high < nums.size()) {
            sum += nums[high];
            while (sum > target) {
                ans = min(ans, high - low + 1);
                sum -= nums[low];
                low++;
            }
            high++;
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};