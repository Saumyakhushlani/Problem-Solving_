class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int q = target/sum;
        int r=target%sum;
        if(!r){
            return n*q;
        }
        target=r;
        int ans = INT_MAX;
        int low =0;
        int high=0;
        sum=0;
        while(high<2*n){
            sum+=nums[high%n];
            while(sum>target){
                sum-=nums[low%n];
                low++;
            }
            if(sum==target){
                ans=min(ans,high-low+1);
            }
            high++;
        }
        if(ans==INT_MAX)return -1;
        return q*n+ans;
    }
};