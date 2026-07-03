class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> a(V);
        vector<int> ind(V, 0);

        for (auto i : edges) {
            a[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int k = q.front();
            q.pop();

            ans.push_back(k);

            for (int n : a[k]) {
                ind[n]--;
                if (ind[n] == 0)
                    q.push(n);
            }
        }
        if (ans.size() != V)
            return false; 
        return true;
    }
};