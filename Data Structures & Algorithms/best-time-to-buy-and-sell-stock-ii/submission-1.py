class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        total = 0
        cur = prices[0]

        for i in range(1, len(prices)):
            if cur < prices[i]:
                total += prices[i] - cur

            cur = prices[i]

        return total