class Solution {
  public:
    bool solve(vector<int>& arr,int idx){
        if (idx == arr.size() - 1) {
            return true;
        }
        return arr[idx] <= arr[idx + 1] && solve(arr, idx + 1);
    }
    bool isSorted(vector<int>& arr) {
        // code here
        return solve(arr,0);
        
    }
};