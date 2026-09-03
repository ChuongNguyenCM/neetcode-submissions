class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int x = 0;
        unordered_set <char> set;

        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            x += 1;
            while (set.count(s[r])) {
                set.erase(s[l]);
                ++l;
                --x;
            }
            set.insert(s[r]);
            ans = max(ans, x);
        }

        return ans;
    }
};
