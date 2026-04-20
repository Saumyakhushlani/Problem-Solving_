class Solution {
public:
    int reverseNum(int n) {
        int ret = 0;
        while (n) {
            ret = ret * 10 + (n % 10);
            n = n / 10;
        }

        return ret;
    }
    int minMirrorPairDistance(vector<int>& nums) {
         int n = nums.size();

        unordered_map<int, int> hash;
        int min_val = INT_MAX;
        for (int i = 0; i < n; i++) {
            int rev_num = reverseNum(nums[i]);

            if(hash.count(nums[i])){
                min_val = min(min_val, abs(hash[nums[i]] - i));
            }

            hash[rev_num] = i;
        }

        if(min_val == INT_MAX) return -1;
        return min_val;
    
    }
};