class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)

        prefix = 0
        ans = 0
        count[0] = 1

        for n in nums:
            prefix += n
            ans += count[prefix - k]
            count[prefix] += 1

        return ans