class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int low =0;
        int high =0;
        int mx=1;
        while(high<fruits.size()){
            mpp[fruits[high]]++;

            while(mpp.size()>2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]]==0)mpp.erase(fruits[low]);
                low++;
            }
            if(mpp.size()<=2){
                mx=max(mx,high-low+1);
            }
            high++;
        }
        return mx;
    }
};