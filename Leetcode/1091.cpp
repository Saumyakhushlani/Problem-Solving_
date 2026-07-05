class Solution {
public:
    bool validate(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, 0});
        vis[0][0] = 1;
        int dist = 1;
        vector<int> x = {1, 1, 1, 0, 0, -1, -1, -1};
        vector<int> y = {1, 0, -1, 1, -1, 1, 0, -1};
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if (r == n - 1 && c == m - 1)
                    return dist;
                for (int i = 0; i < 8; i++) {
                    int nr = r + x[i];
                    int nc = c + y[i];
                    if (validate(nr, nc, n, m) && grid[nr][nc] == 0 &&
                        vis[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};