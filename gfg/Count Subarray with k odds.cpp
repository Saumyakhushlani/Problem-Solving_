class Solution {
  public:
    int solve(vector<int>& nums, int k){
        int low =0;
        int high =0;
        int cnt=0;
        int od=0;
        while(high<nums.size()){
            if(nums[high]%2!=0)od++;
            while(od>k){
                if(nums[low]%2!=0)od--;
                low++;
            }
            cnt+=high-low+1;
            high++;
        }
        return cnt;
    }
    int countSubarrays(vector<int>& nums, int k) {
        // code here
        return solve(nums,k)-solve(nums,k-1);
        
    }
};