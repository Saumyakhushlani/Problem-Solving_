class Solution {
public:
    bool validate(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist (n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d= p.first;
            int i=p.second.first;
            int j=p.second.second;

            if(i==n-1 && j==m-1)return d;
            if(d>dist[i][j])continue;

            for(int k=0;k<4;k++){
                int ni = i +x[k];
                int nj = j +y[k];
                if(validate(ni,nj,n,m)){
                    int nd = max(d,grid[ni][nj]);
                    if(nd<dist[ni][nj]){
                        dist[ni][nj]=nd;
                        pq.push({nd,{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};