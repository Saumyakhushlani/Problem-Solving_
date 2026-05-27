class Solution
{
public:
    int solve(vector<int> &v)
    {
        int n = v.size();
        int prev2 = 0;
        int prev1 = v[0];
        int ans;
        for (int i = 1; i < n; i++)
        {
            int inc = prev2 + v[i];
            int exc = prev1;
            int ans = max(inc, exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> first, second;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != n - 1)
                first.push_back(nums[i]);
            if (i != 0)
                second.push_back(nums[i]);
        }
        int ans1 = solve(first);
        int ans2 = solve(second);
        int ans = max(ans1, ans2);
        return ans;
    }
};
