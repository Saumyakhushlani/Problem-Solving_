class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        int n = word.size();

        for(int i = 0; i < n; i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                lastLower[word[i] - 'a'] = i;
            }
            else {
                int idx = word[i] - 'A';
                if(firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }
        int res = 0;

        for(int i = 0; i < 26; i++) {
            if(lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                res++;
            }
        }
        return res;
    }
};