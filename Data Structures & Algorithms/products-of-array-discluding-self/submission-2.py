class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_index = -1
        product = 1

        for i, x in enumerate(nums):
            if x == 0:
                if zero_index != -1:
                    return [0] * len(nums)
                zero_index = i
            else:
                product *= x

        # Exactly one zero
        if zero_index != -1:
            ans = [0] * len(nums)
            ans[zero_index] = product
            return ans

        # No zero
        return [product // x for x in nums]