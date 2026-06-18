class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>sumleft(n);
        int sl=0;
        vector<int>sumright(n);
        int sr=0;
        for(int i=0;i<n;i++){
            sl+=nums[i];
            sr+=nums[n-i-1];
            sumleft[i]=sl;
            sumright[n-i-1]=sr;
        }
        for(int i=0;i<n;i++){
            if(sumleft[i]==sumright[i])return i;
        }
        return -1;
    }
};