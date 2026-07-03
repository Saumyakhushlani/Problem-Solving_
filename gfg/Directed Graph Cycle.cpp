class Solution {
  public:
    bool cycle = false;
    void dfs(vector<vector<int>>& a, int node,vector<int>& visited, vector<int>& path){
        visited[node]=1;
        path[node]=1;
        for(int i=0;i<a[node].size();i++){
            int k = a[node][i];
            if(visited[k]==1 && path[k]==1)cycle = true;
            else if(visited[k]==0){
                dfs(a,k,visited,path);
            }
            
        }
        path[node]=0;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> a(V);
        for(auto i:edges){
            a[i[0]].push_back(i[1]);
        }
        vector<int> visited(V,0);
        vector<int> path(V,0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(a, i, visited, path);
            }
        }
        return cycle;
        
    }
};