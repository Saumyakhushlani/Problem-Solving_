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
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color (graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                dfs(graph,i,0,color);
            }
        }
        return bp;
    }
};