class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
            if (p1.first < p2.first) {
                return true;
            } else if (p1.first == p2.first && p1.second < p2.second) {
                return true;
            }
            return false;
        }
    };
    int solve(vector<int>& v) {
        int l=0; int h=v.size()-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(v[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
        for(int i=0;i<mat.size();++i){
            pq.push({solve(mat[i]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};