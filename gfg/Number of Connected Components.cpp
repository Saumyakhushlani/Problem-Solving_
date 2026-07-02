class Solution {
  public:
    void dfs(vector<vector<int>>& a, vector<int>& visited, int i) {
        visited[i] = 1;
        for (int neigh : a[i]) {
            if (!visited[neigh]) {
                dfs(a, visited, neigh);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> a(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            a[u].push_back(v);
            a[v].push_back(u);
        }
        int n = a.size();
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(a, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};