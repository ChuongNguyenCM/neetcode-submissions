class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        count = {}

        for i, x in enumerate(nums):
            if (x not in count):
                count[x] = i
                continue
            
            if (i - count[x] <= k):
                return True
            count[x] = i

        return False
