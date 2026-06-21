class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int>v(nums.size(), 0);;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top() - i;
            }
            st.push(i);

        }
        return v;
    }
};