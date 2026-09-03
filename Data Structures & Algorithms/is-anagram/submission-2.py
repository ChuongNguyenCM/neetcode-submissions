class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False
        map1 = {}
        map2 = {}
        for a, b in zip(s, t):
            map1[a] = map1.get(a, 0) + 1
            map2[b] = map2.get(b, 0) + 1

        if (map1 == map2):
            return True
        return False