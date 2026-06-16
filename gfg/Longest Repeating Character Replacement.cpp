class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int low =0;
        int high=0;
        int mx=INT_MIN;
        int maxFreq=0;
        unordered_map<char,int>mpp;
        while(high<s.size()){
            mpp[s[high]]++;
            int len = high-low+1;
            maxFreq = max(maxFreq, mpp[s[high]]);

            while (len - maxFreq > k) {
                mpp[s[low]]--;
                low++;
                len = high - low + 1;
            }

            mx = max(mx, len);


            high++;
        }
        return mx;
    }
};