class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis,int n){
        vis[n]=1;
        for(auto i:adj[n]){
            if(vis[i]==0){
                dfs(adj,vis,i);
            }
        }
    }
    int minConnect(int n, vector<vector<int>>& connections) {
        // Code here
        if(connections.size()<n-1)return -1;   
        int cnt=0;
        vector<vector<int>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt-1;
    }
};
