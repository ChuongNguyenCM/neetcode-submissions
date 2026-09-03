class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != (int)s3.size()) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (!dp[0][i - 1]) continue;
            else {
                if (s2[i - 1] == s3[i - 1]) dp[0][i] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!dp[i - 1][0]) continue;
            else {
                if (s1[i - 1] == s3[i - 1]) dp[i][0] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((dp[i - 1][j] && s1[i - 1] == s3[i + j -1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j -1])) {
                    dp[i][j] = true;
                } else continue;
            }
        }

        return dp[n][m];
    }
};
