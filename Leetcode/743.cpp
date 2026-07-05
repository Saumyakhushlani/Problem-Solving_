class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<vector<pair<int, int>>> a(n + 1);
        for (auto i : times) {
            a[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({dist[k], k});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int nd = p.second;
            if (dist[nd] < d) {
                continue;
            }
            for (auto ng : a[nd]) {
                if (d + ng.second < dist[ng.first]) {
                    dist[ng.first] = d + ng.second;
                    pq.push({dist[ng.first], ng.first});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};