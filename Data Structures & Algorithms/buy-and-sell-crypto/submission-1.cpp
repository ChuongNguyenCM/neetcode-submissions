class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int x = INT_MAX;

        for (int r = 0; r < prices.size(); ++r) {
            x = min(x, prices[r]);
            ans = max(ans, prices[r] - x);
        }

        return ans;
    }
};
