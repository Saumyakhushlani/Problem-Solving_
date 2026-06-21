class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> f(100001);

        for (int cost : costs)
            f[cost]++;

        int ans = 0;

        for (int price = 1; price <= 100000; price++) {
            if (f[price] == 0)
                continue;

            int canBuy = min(f[price], coins / price);

            ans += canBuy;
            coins -= canBuy * price;

            if (coins < price)
                break;
        }
        return ans;
    }
};