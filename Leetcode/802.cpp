class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> g(graph.size());
        vector<int> ind(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for (auto it : graph[i]) {
                g[it].push_back(i);  
                ind[i]++;  
            }
        }
        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            if (ind[i] == 0)
                q.push(i);
        }
        vector<int> ans;

        while (!q.empty()) {
            int k = q.front();
            q.pop();

            ans.push_back(k);

            for (int n : g[k]) {
                ind[n]--;
                if (ind[n] == 0)
                    q.push(n);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};