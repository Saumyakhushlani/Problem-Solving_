class Solution {
public:
    vector<int>x= {-1,1,0,0};
    vector<int>y= {0,0,1,-1};
    bool validate(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    void dfs(vector<vector<char>>& a,int i,int j,vector<vector<int>>& visited,int n,int m){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(validate(row,col,n,m) && visited[row][col]==0 && a[row][col]=='X'){
                dfs(a,row,col,visited,n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='X'){
                    dfs(grid,i,j,visited,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};