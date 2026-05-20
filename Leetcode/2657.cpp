class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> seenA;
        unordered_set<int> seenB;

        int common = 0;
        vector<int> ans;

        for (int i = 0; i < A.size(); i++) {

            int a = A[i];
            int b = B[i];

            seenA.insert(a);
            seenB.insert(b);

            if (seenB.count(a)) {
                common++;
            }

            if (seenA.count(b) && a != b) {
                common++;
            }

            ans.push_back(common);
        }

        return ans;
    }
};w