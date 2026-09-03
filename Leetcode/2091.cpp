class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(mn,mx);
        int r = max(mn,mx);
         int f = r + 1;
        int b = nums.size() - l;
        int k = l + 1 + (nums.size() - r);

        return min({f, b, k});
    }
};