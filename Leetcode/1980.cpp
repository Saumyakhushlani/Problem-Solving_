class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string a="";
        for(int i=0;i<nums.size();i++){
            char ch = (nums[i][i]=='0')?'1':'0';
            a+=ch;
        }
        return a;

    }
};