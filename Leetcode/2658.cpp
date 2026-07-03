class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int mx = 0;

    bool validate(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited,
            int i, int j, int n, int m) {

        visited[i][j] = 1;
        int sum = grid[i][j];

        for (int k = 0; k < 4; k++) {
            int r = i + x[k];
            int c = j + y[k];

            if (validate(r, c, n, m) &&
                !visited[r][c] &&
                grid[r][c] != 0) {

                sum += dfs(grid, visited, r, c, n, m);
            }
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    mx = max(mx, dfs(grid, visited, i, j, n, m));
                }
            }
        }

        return mx;
    }
};