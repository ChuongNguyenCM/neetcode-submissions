class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        map = {}

        for n in nums:
            if n == val:
                continue
            map[n] = map.get(n, 0) + 1
            k += 1

        index = 0
        for key, value in map.items():
            for i in range(value):
                nums[index] = key
                index += 1

        return k