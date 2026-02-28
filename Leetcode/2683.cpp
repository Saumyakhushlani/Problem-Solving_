class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for(auto derive: derived){
            xr^=derive;
        }
        return xr==0? true:false;
    }
};