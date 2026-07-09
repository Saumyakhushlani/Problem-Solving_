class Solution {
  public:
    int findCheapestCost(int V, vector<vector<int>>& edges, int src, int dst, int k) {
        // code here
        int n = V;
		vector<int>dist(n, 1e8);
        if(k<V)n=k;
		dist[src] = 0;
		for (int i = 0; i <=n; i++) {
            vector<int> temp = dist;
            for (auto &k : edges) {

                int sr = k[0];
                int ds = k[1];
                int wt = k[2];

                if (dist[sr] != 1e8 && temp[ds] > dist[sr] + wt) {
                    temp[ds] = dist[sr] + wt;
                }
            }
            dist = temp;
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};
