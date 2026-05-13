class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int j:nums){
            string s = to_string(j);
            for(int i=0;i<s.size();i++) ans.push_back(s[i]-'0');
        }
        return ans;
    }
};