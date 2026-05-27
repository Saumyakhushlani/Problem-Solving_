class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            int x = num;
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {
            int x = num;

            while (x > 0) {
                if (prefixes.count(x)) {
                    ans = max(ans, (int)to_string(x).size());
                    break;
                }
                x /= 10;
            }
        }

        return ans;
    }
};