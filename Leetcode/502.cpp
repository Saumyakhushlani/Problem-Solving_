class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> v;
        for (int i = 0; i < profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int idx = 0;
        priority_queue<int> pq;
        while (k--) {
            while (idx < v.size()) {
                if (v[idx].first > w) {
                    break;
                }
                pq.push(v[idx].second);
                idx++;
            }
            if(pq.empty())return w;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};