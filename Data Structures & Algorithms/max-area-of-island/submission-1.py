class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = set()
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        ans = 0

        def dfs(i, j):
            visited.add((i, j))
            curr = 1

            for di, dj in directions:
                ni, nj = i + di, j + dj

                if not (0 <= ni < n and 0 <= nj < m):
                    continue

                if (ni, nj) in visited:
                    continue

                if grid[ni][nj] != 1:
                    continue

                curr += dfs(ni, nj)
            return curr

        for i in range(n):
            for j in range(m):
                if (i, j) not in visited and grid[i][j] == 1:
                    ans = max(ans, dfs(i, j))

        return ans