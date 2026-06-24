class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int maxPages) {
        int students = 1;
        int pages = 0;
        
        for (int x : arr) {
            if (pages + x <= maxPages) {
                pages += x;
            } else {
                students++;
                pages = x;
                
                if (students > k)
                    return false;
            }
        }
        
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        if (k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        
        return ans;
        
    }
};