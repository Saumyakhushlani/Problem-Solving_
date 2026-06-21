class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for (auto a : text) mp[a]++;
        int mn = mp['b'];
        mn = min(mn, mp['a']);
        mn = min(mn, mp['l'] / 2);
        mn = min(mn, mp['o'] / 2);
        mn = min(mn, mp['n']);
        return mn;        
    }
};