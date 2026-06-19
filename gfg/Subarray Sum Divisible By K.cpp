class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& nums, int k) {
        // Your code goes here
        unordered_map<int, long long> freq;

        freq[0] = 1;

        long long sum = 0;
        long long ans = 0;

        for (int x : nums) {
            sum += x;

            int rem = ((sum % k) + k) % k;

            ans += freq[rem];
            freq[rem]++;
        }

        return ans;
    }
};
