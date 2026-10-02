class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, sums = 0, 0
        ans = float('inf')

        for r, x in enumerate(nums):
            sums += x

            while sums >= target:
                ans = min(r - l + 1, ans)
                sums -= nums[l]
                l += 1

        return 0 if ans == float('inf') else ans