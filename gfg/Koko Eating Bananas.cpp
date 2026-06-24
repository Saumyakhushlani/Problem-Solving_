class Solution {
  public:
    int kokoEat(vector<int>& piles, int k) {
        // Code here
        long long mx = *max_element(piles.begin(), piles.end());
        int low=1;
        int high=mx;
        int ans=mx;
        while(low<=high){
            int mid = low+(high-low)/2;
            int h=0;
            for(int pile:piles){
                if(pile%mid==0)h+=pile/mid;
                else{
                    h+=pile/mid;
                    h++;
                }
            }
            if(h>k){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};