class Solution {
  public:
    int maxCircularSum(vector<int> &nums) {
        // code here
        int best=nums[0];
        int mx=nums[0];
        int mxbest=nums[0];
        int ans =nums[0];
        for(int i=1;i<nums.size();i++){
            best = min(best+nums[i],nums[i]);
            mxbest = max(mxbest+nums[i],nums[i]);
            ans=min(ans,best);
            mx=max(mx,mxbest);
        }
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if (mx < 0) return mx; 

        return max(mx, sum - ans);

    }
};