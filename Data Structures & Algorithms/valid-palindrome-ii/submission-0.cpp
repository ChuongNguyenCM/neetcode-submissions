class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        int x = -1, y = -1;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l; 
                --r;
            } else {
                x = l; 
                y = r;
                break;
            }
        }

        if (r <= l) return true;

        if (check(s, x + 1, y)) return true;
        if (check(s, x, y - 1)) return true;

        return false;
    }

    bool check(string& s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                ++l; --r;
            } else {
                return false;
            }
        }

        return true;
    }
};