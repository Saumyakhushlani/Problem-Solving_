class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [&](vector<int>& a, vector<int>& b) { return a[1]-a[0] > b[1]-b[0]; });
        int a =tasks[0][1];
        int b = tasks[0][1]-tasks[0][0];
        int req=0;
        for(int i=1;i<tasks.size();i++){
            vector<int>v= tasks[i];
            if(b<v[1]){
                req+=v[1]-b;
                b=v[1];
            }
            b-=v[0];
        }
        return a+req;
    }
};