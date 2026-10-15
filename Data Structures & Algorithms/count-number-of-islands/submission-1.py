class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        count = 0

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(i, j):
            if not (0 <= i < n and 0 <= j < m):
                return

            if grid[i][j] != "1":
                return

            grid[i][j] = "0"

            for di, dj in directions:
                dfs(i + di, j + dj)

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    count += 1
                    dfs(i, j)

        return count