class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        setdead = set(deadends)

        if "0000" in setdead:
            return -1

        queue = deque([[0, 0, 0, 0]])
        visited = {"0000"}

        ans = 0

        while queue:
            for _ in range(len(queue)):
                l = queue.popleft()

                current = "".join(map(str, l))

                if current == target:
                    return ans

                for i in range(4):
                    for change in [1, -1]:
                        new_l = l.copy()
                        new_l[i] = (new_l[i] + change) % 10

                        x = "".join(map(str, new_l))

                        if x in visited or x in setdead:
                            continue

                        visited.add(x)
                        queue.append(new_l)

            ans += 1

        return -1