class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        if (src == dest) return 0;
        queue<int> q;
        vector<vector<int>> a(V);
        for(auto i:edges){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        vector<int> vis(V, 0);
        vis[src] = 1;
        q.push(src);
        int n=0;
        while(!q.empty()){
            int k=q.size();
            while (k--) {
                int node = q.front();
                q.pop();

                if (node == dest)
                    return n;

                for (int nei : a[node]) {
                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            n++;
        }
        return -1;
    }
};
