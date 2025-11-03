class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int k = 0;
        int time = 0;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[k]) {
                time += min(neededTime[i], neededTime[k]);
                if (neededTime[i] > neededTime[k])
                    k = i;
            } else {
                k = i;
            }
        }
        return time;
    }
};
