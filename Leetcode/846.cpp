class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mpp;

        for (int i : hand)
            mpp[i]++;

        for (auto it : mpp) {
            int start = it.first;
            int count = it.second;

            if (count > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (mpp[start + i] < count)
                        return false;

                    mpp[start + i] -= count;
                }
            }
        }

        return true;
    }
};