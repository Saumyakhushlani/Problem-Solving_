class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a,
                        const pair<int, int>& b) const {
            return a.first > b.first;
        }
    };

    int findDelayTime(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int, int>>> adj(V);

        for (const auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       cmp> pq;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (const auto &[v, wt] : adj[u]) {
                if (dist[v] > d + wt) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};