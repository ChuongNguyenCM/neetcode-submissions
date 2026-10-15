class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust1 = [[] for _ in range(n)]
        trusted = [[] for _ in range(n)]

        for a, b in trust:
            trust1[a - 1].append(b - 1)
            trusted[b - 1].append(a - 1)

        for i in range(n):
            if len(trust1[i]) == 0 and len(trusted[i]) == n - 1:
                return i + 1

        return -1