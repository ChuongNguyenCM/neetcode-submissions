class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n, m = len(s1), len(s2)

        if n + m != len(s3):
            return False

        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True

        for i in range(n):
            if not dp[i][0]:
                dp[i + 1][0] = False
            else:
                dp[i + 1][0] = (s1[i] == s3[i])

        for i in range(m):
            if not dp[0][i]:
                dp[0][i + 1] = False
            else:
                dp[0][i + 1] = (s2[i] == s3[i])

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if not dp[i - 1][j] and not dp[i][j - 1]:
                    dp[i][j] = False
                    continue

                a, b = False, False

                if dp[i - 1][j]:
                    a = (s1[i - 1] == s3[i + j - 1])

                if dp[i][j - 1]:
                    b = (s2[j - 1] == s3[i + j - 1])

                dp[i][j] = a or b

        return dp[n][m]