class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]

        for a, b in prerequisites:
            graph[b].append(a)

        state = [0] * numCourses

        def dfs(u):
            if state[u] == 1:
                return False

            if state[u] == 2:
                return True

            state[u] = 1

            for v in graph[u]:
                if not dfs(v):
                    return False

            state[u] = 2
            return True

        return all(dfs(u) for u in range(numCourses) if state[u] == 0)