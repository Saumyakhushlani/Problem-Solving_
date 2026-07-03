class Solution {
  public:
    bool bp =true;
    void dfs(vector<vector<int>>& a,int node,int c,vector<int>& color){
        color[node]=c;
        for(int i=0;i<a[node].size();i++){
            int k =a[node][i];
            if(color[k]!=-1 && color[k]==c)bp = false;
            else if(color[k]==-1) dfs(a,k,1-c,color);
        }
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> graph(V);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int>color (graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                dfs(graph,i,0,color);
            }
        }
        return bp;
    }
};