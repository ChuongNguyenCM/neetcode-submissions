from collections import deque

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n, m = len(board), len(board[0])

        queue = deque()
        visited = set()

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        # Step 1: Find all border O cells
        for i in range(n):
            for j in range(m):
                if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                    if board[i][j] == "O":
                        queue.append((i, j))
                        visited.add((i, j))

        # Step 2: BFS from border O cells
        while queue:
            x, y = queue.popleft()

            for di, dj in directions:
                nx, ny = x + di, y + dj

                if not (0 <= nx < n and 0 <= ny < m):
                    continue

                if (nx, ny) in visited:
                    continue

                if board[nx][ny] != "O":
                    continue

                visited.add((nx, ny))
                queue.append((nx, ny))

        # Step 3: Capture all unvisited O cells
        for i in range(n):
            for j in range(m):
                if board[i][j] == "O" and (i, j) not in visited:
                    board[i][j] = "X"