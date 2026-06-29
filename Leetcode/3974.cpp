class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int,vector<int>, greater<int>>pq;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> v;
        while (!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }

        sort(v.rbegin(), v.rend());

        long long ans = 0;
        int cur = mul;

        for (int i = 0; i < v.size(); i++) {
            if (cur > 1) {
                ans += 1LL * v[i] * cur;
            } else {
                ans += v[i];
            }
            cur--;
        }

        return ans;
    }
};