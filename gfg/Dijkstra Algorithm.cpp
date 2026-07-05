class Solution {
  public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);

        for (auto &i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        vector<int> dis(V, INT_MAX);
        dis[src] = 0;

        pq.push({0, src});
        while(!pq.empty()){
             auto p = pq.top();
            pq.pop();

            int d = p.first;
            int u = p.second;
            if (d > dis[u])
                continue;

            for (auto &ng : adj[u]) {
                int v = ng.first;
                int wt = ng.second;

                if (d + wt < dis[v]) {
                    dis[v] = d + wt;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};