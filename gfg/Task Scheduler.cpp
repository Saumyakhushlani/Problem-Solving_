class Solution {
  public:
    int leastInterval(int N, int n, vector<char> &tasks) {
        // code here
         unordered_map<char, int> freq;

        int maxFreq = 0;
        for(auto n: tasks){
            freq[n]++;
            maxFreq = max(maxFreq, freq[n]);
        }

        int count = 0;
        for(char c = 'A'; c <= 'Z'; ++c){
            if(freq[c] == maxFreq){
                count++;
            }
        }

        int len = (n + 1) * (maxFreq - 1) + 1;
        return max((int)tasks.size(), len + count - 1);
    }
};