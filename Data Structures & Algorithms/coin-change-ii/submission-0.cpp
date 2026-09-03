class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector(coins.size() + 1, 0));

        for (int i = 0; i <= coins.size(); i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= coins.size(); j++) {
                int skip = dp[i][j - 1];
                int include = 0;
                if (coins[j - 1] <= i) {
                    include = dp[i - coins[j - 1]][j];
                }
                dp[i][j] = skip + include;
            }
        }

        return dp[amount][coins.size()];
    }
};
