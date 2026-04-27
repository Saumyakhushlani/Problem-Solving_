class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        int me = max_element(nums.begin(),nums.end()) - nums.begin();
        long long ascsum=0,descsum=0;
        for(int i=0;i<=me;i++){
            ascsum+=nums[i];
        }
        for(int i=me;i<n;i++){
            descsum+=nums[i];
        }
        if(ascsum>descsum) return 0;
        if(descsum>ascsum) return 1;
        return -1;
    }
};