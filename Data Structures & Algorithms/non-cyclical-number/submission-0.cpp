class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int x = 0;
        while (n != 1) {
            while (n > 0) {
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            n = x;
            x = 0;
            if (set.count(n)) {
                return false;
            } else {
                set.insert(n);
            }
        }

        return true;
    }
};
