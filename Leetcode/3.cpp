class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        int low=0;
        int high =0;
        unordered_map<char,int>mpp;
        while(high<s.size()){
            while(mpp[s[high]]!=0){
                mpp[s[low]]--;
                low++;
            }
            mpp[s[high]]++;
            mx=max(high-low+1,mx);
            high++;
        }
        return mx;
    }
};