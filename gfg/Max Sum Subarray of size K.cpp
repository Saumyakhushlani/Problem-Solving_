class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
         int n = arr.size();

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        long long ans = sum;

        int low = 0;
        int high = k - 1;

        while (high < n - 1) {
            sum -= arr[low++];
            sum += arr[++high];
            ans = max(ans, sum);
        }

        return ans;
    }
};