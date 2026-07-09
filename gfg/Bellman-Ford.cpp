class Solution {
	public:
	vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		// Code here
		int n = V;
		vector<int>dist(n, 1e8);
		dist[src] = 0;
		for (int i = 0; i < V - 1; i++) {
            for (auto &k : edges) {
                int sr = k[0];
                int ds = k[1];
                int wt = k[2];

                if (dist[sr] != 1e8 && dist[ds] > dist[sr] + wt) {
                    dist[ds] = dist[sr] + wt;
                }
            }
        }
		 for (auto &k : edges) {
            int sr = k[0];
            int ds = k[1];
            int wt = k[2];

            if (dist[sr] != 1e8 && dist[ds] > dist[sr] + wt) {
                return {-1};
            }
        }
		return dist;
	}
};
