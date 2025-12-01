class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(int n : nums){
            mpp[n]++;
        }

        vector<pair<int,int>> p;
        for(auto &N : mpp){
            p.push_back({N.first, N.second});
        }
        sort(p.begin(), p.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(p[i].first);
        }

        return ans;
    }
};