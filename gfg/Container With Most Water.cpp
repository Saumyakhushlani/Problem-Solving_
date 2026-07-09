class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
         int i = 0;
        int j = arr.size() - 1;
        int res = 0;

        while (i < j) {
            res = max(res, (j - i) * min(arr[i], arr[j]));
            if (arr[i] < arr[j]) i++;
            else j--;
        }

        return res;
    }
};