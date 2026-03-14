class Solution {
public:
    long long minNumberOfSeconds(long long m, vector<int>& k) {
        long long mx = *max_element(k.begin(),k.end());
        long long high = (m*(m+1)*mx)/2;
        long long low = 0;
        long long ans = high;
        while(low<=high){
            long long mid = low +(high - low)/2;
            long long height = 0;
            for(long long i:k){
                long long val = (long long)(sqrt(1 + 8.0 * mid / i) - 1) / 2;
                height += val;
            }
            if(height<m){
                low = mid+1;
            }
            else if(height>=m){
                high = mid -1;
                ans=mid;
            }
        }
        return ans;
    }
};