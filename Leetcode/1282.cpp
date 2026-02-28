class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> k;
        vector<vector<int>> result;

        for(int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            k[size].push_back(i);
            
            if(k[size].size() == size) {
                result.push_back(k[size]);
                k[size].clear();
            }
        }
        return result;
    }
};