class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        unordered_map<int,int>freqPrev;
        unordered_map<int,int>freqNext;
        for(int i:nums){
            freqNext[i]++;
        }
         long ans=0;
        for(int i:nums){
            freqNext[i]--;
            ans+=(long)freqPrev[2*i]*freqNext[2*i];
            freqPrev[i]++;
        }
        return ans%mod;

    }
};