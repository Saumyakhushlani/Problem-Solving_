class Solution {
public:
    bool canConstruct(string ransomNote, string s) {
        unordered_map<char, int> mp;

        for (auto a : s) mp[a]++;
        for(char c: ransomNote){
            if(mp[c]>0){
                mp[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};