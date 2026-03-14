class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long mx = *max_element(piles.begin(), piles.end());
        
        long long low = 1, high = mx;
        long long ans = mx;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long hours = 0;

            for(int pile : piles){
                hours += (pile + mid - 1) / mid;   
            }

            if(hours <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};