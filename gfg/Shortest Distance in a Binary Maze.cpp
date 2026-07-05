class Solution {
public:
    bool validate(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int shortestPath(vector<vector<int>> &grid, vector<int> &src, vector<int> &dest) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[src[0]][src[1]] == 0 || grid[dest[0]][dest[1]] == 0)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        q.push({src[0], src[1]});
        vis[src[0]][src[1]] = 1;

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                if (r == dest[0] && c == dest[1])
                    return dist;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (validate(nr, nc, n, m) &&
                        grid[nr][nc] == 1 &&
                        !vis[nr][nc]) {

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