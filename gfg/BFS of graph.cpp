class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<int>res;
        vector<int>vis(adj.size());
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int c = q.front();
                q.pop();
                res.push_back(c);
                for(int j=0;j<adj[c].size();j++){
                    if(vis[adj[c][j]]==0){
                        q.push(adj[c][j]);
                        vis[adj[c][j]]=1;
                    }
                }
            }
        }
        return res;
    }
};