class Solution {
  public:
    void dfs(vector<vector<int>>& adj,int node, vector<int>&res, vector<int>& visited){
        visited[node]=1;
        res.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            int n = adj[node][i];
            if(visited[n]==0){
                dfs(adj,n,res,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int>visited(v,0);
        vector<int>res;
        dfs(adj,0,res,visited);
        return res;
    }
};