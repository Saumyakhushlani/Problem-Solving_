class Solution {
  public:
    vector<vector<int>> findIntersection(vector<vector<int>> fl, vector<vector<int>> sl) {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < fl.size() && j < sl.size()) {
            vector<int> f = fl[i];
            vector<int> s = sl[j];
            int start = max(f[0], s[0]);
            int end = min(f[1], s[1]);
            if (start <= end)
                res.push_back({start, end});
            if (fl[i][1] < sl[j][1])
                i++;
            else
                j++;
        }
        return res;
    }
};