class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0)zeroCount++;
            else{
                nums[i++]=nums[j];
            }
        }
        for(int k=i;i<nums.size();i++){
            nums[i]=0;
        }
        
    }
};