class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int m = 0;
        for (int x : nums) m += x;

        if (target < -m || target > m) return 0;      // out of reachable range

        int W = 2 * m + 1;                             // number of columns (indices 0..2m)
        auto idx = [&](int s){ return s + m; };        // map sum s in [-m,m] to [0..2m]

        vector<vector<int>> dp(n, vector<int>(W, 0));

        // base row i=0
        int a = nums[0];
        dp[0][idx(+a)] += 1;
        dp[0][idx(-a)] += 1;                           // if a==0, this makes it 2 (correct)

        // fill
        for (int i = 1; i < n; ++i) {
            int val = nums[i];
            for (int j = 0; j < W; ++j) {              // j is an index (0..2m)
                int ways = 0;
                int j_plus  = j - val;                 // index for sum (currentSum - val)
                int j_minus = j + val;                 // index for sum (currentSum + val)
                if (0 <= j_plus  && j_plus  < W) ways += dp[i-1][j_plus];
                if (0 <= j_minus && j_minus < W) ways += dp[i-1][j_minus];
                dp[i][j] = ways;
            }
        }

        return dp[n-1][idx(target)];
    }
};
