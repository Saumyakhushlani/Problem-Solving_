class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp){
        if(nums.size()==0){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            tmp.push_back(nums[i]);
            int k= nums[i];
            nums.erase(nums.begin()+i);
            solve(nums,res,tmp);
            tmp.pop_back();
            nums.insert(nums.begin() + i, k);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        solve(nums,res,tmp);
        return res;
    }
};