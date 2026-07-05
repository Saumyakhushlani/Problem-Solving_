class Solution {
  public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0LL, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, wt] : adj[u]) {
                long long nd = d + 1LL * wt;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                }
                else if (nd == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};