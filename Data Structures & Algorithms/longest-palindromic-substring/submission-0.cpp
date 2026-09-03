class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> check(2, 0);

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > check[1] - check[0] + 1) {
                    check[0] = l;
                    check[1] = r;
                }

                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > check[1] - check[0] + 1) {
                    check[0] = l;
                    check[1] = r;
                }

                l--;
                r++;
            }
        }

        return s.substr(check[0], check[1] - check[0] + 1);
    }
};
