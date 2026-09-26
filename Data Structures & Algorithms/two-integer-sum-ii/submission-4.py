class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i, j = 0, len(numbers) - 1

        while (i < j):
            x, y = numbers[i], numbers[j]
            if (x + y > target):
                j -= 1
            elif (x + y < target):
                i += 1
            else:
                break

        return [i + 1, j + 1]