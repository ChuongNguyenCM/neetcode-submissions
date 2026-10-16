class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        q = deque()
        fresh = 0

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        # Step 1: Find all rotten oranges
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1

        minutes = 0

        # Step 2: Multi-Source BFS
        while q and fresh > 0:
            for _ in range(len(q)):
                i, j = q.popleft()

                for di, dj in directions:
                    ni, nj = i + di, j + dj

                    if not (0 <= ni < n and 0 <= nj < m):
                        continue

                    if grid[ni][nj] != 1:
                        continue

                    grid[ni][nj] = 2
                    fresh -= 1
                    q.append((ni, nj))

            minutes += 1

        return minutes if fresh == 0 else -1