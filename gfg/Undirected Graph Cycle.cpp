class Solution {
  public:
    bool cycle = false;
    void dfs(vector<vector<int>>& a,int parent,int i,vector<int>& visited){
        visited[i]=1;
        for(int j=0;j<a[i].size();j++){
            if(visited[a[i][j]]==0){
                dfs(a,i,a[i][j],visited);
            }else if(visited[a[i][j]]==1 && parent!=a[i][j]){
                cycle=true;
            }
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>a(V);
        for(auto i:edges){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0)
                dfs(a,-1,i,visited);
        }
        return cycle;
        
    }
};
