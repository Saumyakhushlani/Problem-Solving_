class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        vector<vector<int>> nums;
        bool inserted = false;

        for (auto& curr : intervals) {
            if (!inserted && newInterval[0] < curr[0]) {
                nums.push_back(newInterval);
                inserted = true;
            }
            nums.push_back(curr);
        }

        if (!inserted)
            nums.push_back(newInterval);
        int start1 = nums[0][0];
        int end1 = nums[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < nums.size(); i++) {
            int start2 = nums[i][0];
            int end2 = nums[i][1];
            if (end1 >= start2) {
                end1 = max(end1, end2);
            } else {
                res.push_back({start1, end1});
                start1 = nums[i][0];
                end1 = nums[i][1];
            }
        }
        res.push_back({start1, end1});
        return res;
    }
};