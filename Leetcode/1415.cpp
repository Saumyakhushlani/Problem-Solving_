class Solution {
public:
    string getHappyString(int n, int k) {
        int maxCount = 1 << (n - 1); 
        
        if (k > 3 * maxCount) return "";
        
        string result = "";
        if (k <= maxCount)
            result += 'a';
        else if (k <= 2 * maxCount) {
            result += 'b';
            k -= maxCount;
        } else {
            result += 'c';
            k -= 2 * maxCount;
        }

        for (int i = 1; i < n; i++) {
            maxCount >>= 1;
            
            for (char c : {'a','b','c'}) {
                if (c == result.back()) continue;
                
                if (k > maxCount) {
                    k -= maxCount;
                } else {
                    result += c;
                    break;
                }
            }
        }
        return result;
    }
};