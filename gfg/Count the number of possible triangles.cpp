class Solution {
  public:
    int countTriangles(vector<int>& nums) {
        // code here
        sort(nums.begin(),nums.end());
        int count =0;
        int n=nums.size();
        for(int i=n-1;i>=2;i--){
            int l=0;
            int r=i-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                if(sum>nums[i]){
                    count+=(r-l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        return count;
    }
};
