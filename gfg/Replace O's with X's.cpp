class Solution {
  public:
    vector<int>x= {-1,1,0,0};
    vector<int>y= {0,0,1,-1};
    bool validate(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    void dfs(vector<vector<char>>& a, int i,int j,int n,int m){
        a[i][j]='#';
        for(int k=0;k<4;k++){
            int r = i+x[k];
            int c = j+y[k];
            if(validate(r,c,n,m) && a[r][c]=='O'){
                dfs(a,r,c,n,m);
            }
        }
    }
    void fill(vector<vector<char>>& board) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        int i,j;
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else board[i][j]='X';
            }
        }
    
    }
};