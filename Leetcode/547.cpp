class Solution {
public:
    void dfs(vector<vector<int>>& a, vector<int>& visited, int i) {
        visited[i] = 1;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == 1 && visited[j] == 0) {
                dfs(a, visited, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(a, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};