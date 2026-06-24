class Solution {
  public:
    void rotateArr(vector<int>& nums, int k) {
        // code here
         int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};