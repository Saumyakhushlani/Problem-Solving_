class Solution {
public:
    vector<int> x={1,-1,0,0};
    vector<int> y={0,0,1,-1};
    bool validate(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    void dfs(vector<vector<int>>& a,int i,int j,int n,int m, vector<vector<int>>& vis){
        a[i][j]=0;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r= i+x[k];
            int c= j+y[k];
            if(validate(r,c,n,m) && a[r][c]==1 && vis[r][c]==0){
                dfs(a,r,c,n,m,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && a[i][0]==1){
                dfs(a,i,0,n,m,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][m-1]==0 && a[i][m-1]==1){
                dfs(a,i,m-1,n,m,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && a[0][j]==1){
                dfs(a,0,j,n,m,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(vis[n-1][j]==0 && a[n-1][j]==1){
                dfs(a,n-1,j,n,m,vis);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};