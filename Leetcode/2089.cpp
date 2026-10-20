class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int l=0;
        int h=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target)l++;
            else if(nums[i]>target)h++;
        }
        vector<int>res;
        int k = nums.size()-l-h;
        for(int i=0;i<k;i++){
            res.push_back(i+l);
        }
        return res;
    }
};