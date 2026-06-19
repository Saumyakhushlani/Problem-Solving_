class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int start1=nums[0][0];
        int end1=nums[0][1];
        vector<vector<int>>res;
        for(int i=1;i<nums.size();i++){
            int start2=nums[i][0];
            int end2 =nums[i][1];
            if(end1>=start2){
                end1=max(end1,end2);
            }else{
                res.push_back ({start1,end1});
                start1=nums[i][0];
                end1=nums[i][1];
            }
        }
        res.push_back({start1, end1});
        return res;

    }
};