class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        int low=0;
        int high=k;
        ans.push_back(pq.top().first);
        while(high<nums.size()){
            low++;
            pq.push({nums[high],high});
            while(pq.top().second<low) pq.pop();
            ans.push_back(pq.top().first);
            high++;
        }
        return ans;

    }
};