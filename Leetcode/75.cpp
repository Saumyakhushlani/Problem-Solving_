class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int k=0;
        for(int i=0;i<mpp[0];i++){
            nums[k++]=0;
        }
        for(int i=0;i<mpp[1];i++){
            nums[k++]=1;
        }
        for(int i=0;i<mpp[2];i++){
            nums[k++]=2;
        }
    }
};