class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<pair<int, int>> v;
        for (int i = 0; i < stations.size(); i++) {
            v.push_back({stations[i][0], stations[i][1]});
        }
        sort(v.begin(), v.end());
        int curr=startFuel;
        int cnt=0;
        priority_queue<int> pq;
        int idx=0;
        while(curr<target){
            while (idx < v.size()) {
                if (v[idx].first > curr) {
                    break;
                }
                pq.push(v[idx].second);
                idx++;
            }
            if(pq.empty())return -1;
            curr+=pq.top();
            cnt++;
            pq.pop();
        }
        return cnt;
    }
};