class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        check = {}

        for i, x in enumerate(nums):
            y = target - x

            if y in check:
                return [check[y], i]

            check[x] = i

        return []