class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = defaultdict(int)
        l = 0
        ans = 0

        for r, x in enumerate(s):
            count[x] += 1
            while (count[x] == 2):
                count[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)

        return ans