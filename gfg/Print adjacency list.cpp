class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto i:edges){
            int src=i.first;
            int des=i.second;
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        return adj;
    }
};