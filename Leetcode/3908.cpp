class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char digit = x+'0';
        if(s.find(digit)==string::npos) return false;
        if(s[0]==digit) return false;
        return true;
    }
};