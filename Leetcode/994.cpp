class Solution {
public:
    vector<int>x= {-1,1,0,0};
    vector<int>y= {0,0,1,-1};
    bool validate(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int fresh=0;
        int min=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j] = 1;   
                }
                if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        if(q.empty())return -1;
        while(!q.empty()){
            int sz =q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                visited[p.first][p.second]=1;
                for(int k=0;k<4;k++){
                    int row= p.first+x[k];
                    int col= p.second+y[k];
                    if(validate(row,col,n,m)&& visited[row][col]==0&& grid[row][col]==1){
                        visited[row][col]=1;
                        fresh--;
                        q.push({row,col});
                    }
                }
            }
            min++;
        }
        if(fresh==0)return min;
        return -1;
    }
};