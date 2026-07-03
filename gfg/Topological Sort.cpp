class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<int>> a(V);
        vector<int> ind(V, 0);

        for (auto i : edges) {
            a[i[0]].push_back(i[1]);
            ind[i[1]]++;
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

        return ans;
    }
};