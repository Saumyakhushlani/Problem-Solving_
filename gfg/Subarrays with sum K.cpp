class Solution {
  public:
    int cntSubarrays(vector<int> &nums, int k) {
        // code here
        int sum=0;
        unordered_map<int,int>mpp;
        int res=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int freq = mpp[sum-k];
            res+=freq;
            mpp[sum]++;
        }
        return res;
    }
};