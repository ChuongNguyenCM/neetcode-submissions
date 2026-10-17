class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])

        dist = [[float('inf')] * m for _ in range(n)]
        dist[0][0] = 0

        heap = [(0, 0, 0)]

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while heap:
            effort, r, c = heapq.heappop(heap)

            if effort > dist[r][c]:
                continue

            if r == n - 1 and c == m - 1:
                return effort

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if not (0 <= nr < n and 0 <= nc < m):
                    continue

                diff = abs(heights[r][c] - heights[nr][nc])

                newEffort = max(effort, diff)

                if newEffort < dist[nr][nc]:
                    dist[nr][nc] = newEffort
                    heapq.heappush(heap, (newEffort, nr, nc))

        return 0