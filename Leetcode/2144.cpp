class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int t =0;

        for(int i=cost.size()-1;i>=0;i-=3){
            t += cost[i];
            if(i-1>=0) t+=cost[i-1];
        }

        return t;
    }
};