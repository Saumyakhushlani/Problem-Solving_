class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int m = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forwddist = abs(i - startIndex);
                int backdist = n - forwddist;
                m = min(m, min(forwddist, backdist));
            }
        }

        return m == INT_MAX ? -1 : m;
    }
};