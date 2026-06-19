class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans =0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mpp[rem]>0){
                ans+=mpp[rem];
            }
            mpp[rem]++;
        }
        return ans;
    }
};