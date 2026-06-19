class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int oc=0;
        int zc=0;
        int ans=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)oc++;
            else{
                zc++;
            }
            int diff=oc-zc;
            if(diff==0){
                ans=max(ans,i+1);
                continue;
            }
            if(mpp.find(diff)==mpp.end()){
                mpp[diff]=i;
            }else{
                ans=max(ans,i-mpp[diff]);
            }
        }
        return ans;
    }
};