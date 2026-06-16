class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        int low=0;
        int high=0;
        int mx=-1;
        while (high<s.size()){
            mpp[s[high]]++;
            while (mpp.size() > k) {
                mpp[s[low]]--;
                if (mpp[s[low]] == 0) {
                    mpp.erase(s[low]);
                }
                low++;
            }
            if (mpp.size() == k) {
                mx = max(mx, high - low + 1);
            }

            high++;
        }
        return mx;
    }
};