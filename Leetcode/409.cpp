class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto a : s) mp[a]++;
        int ans=0;
        int k=0;
        for(auto f:mp){
            if(f.second>=2){
                ans+=f.second/2;
            }
            if(f.second%2!=0)k=1;
        }
        return ans*2+k;
    }
};