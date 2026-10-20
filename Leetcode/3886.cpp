class Solution {
public:
    bool fun(vector<int> v1, vector<int> v2) {
        int n = v1.size();
        int m = v2.size();

        if (n > 2 * m)
            return false;

        for (int i = 0; i < m; i++) {
            bool found = true;

            for (int j = 0; j < n; j++) {
                if (v1[j] != v2[(i + j) % m]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return true;
        }

        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 1; i <= n; i++) {
            if (n % i != 0)
                continue;
            bool v = true;
            for (int j = 0; j < n; j += i) {
                vector<int> v1(nums.begin() + j, nums.begin() + j + i);
                vector<int> v2(sorted.begin() + j, sorted.begin() + j + i);
                if (!fun(v1, v2)) {
                    v = false;
                    break;
                }
            }
            if (v) {
                ans += i;
            }
        }
        return ans;
    }
};