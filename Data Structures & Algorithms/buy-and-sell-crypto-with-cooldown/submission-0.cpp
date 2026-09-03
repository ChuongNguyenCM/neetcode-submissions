class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 2, vector(2, 0));
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                int ans = dp[i + 1][j];
                if (j == 1) {
                    ans = max(ans, prices[i] + dp[i + 2][0]);
                } else {
                    ans = max(ans, -prices[i] + dp[i + 1][1]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
};
