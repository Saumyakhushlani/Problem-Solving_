class Solution {
  public:
    int maxOnes(vector<int>& nums, int k) {
        // code here
        int low =0;
        int high=0;
        int count=0;
        int ans=0;
        while(high<nums.size()){
            if(nums[high]==1)count++;
            int len = high-low+1;

            if(len-count>k){
                if(nums[low]==1)count--;
                low++;
                len=high-low+1;
            }

            ans=max(ans,len);
            high++;
        }
        return ans;
    }
};
