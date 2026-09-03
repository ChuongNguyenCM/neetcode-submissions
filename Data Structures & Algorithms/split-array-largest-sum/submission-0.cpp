class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (int i: nums) r += i;

        while (l < r) {
            int m = (r - l) / 2 + l;
            if (check(nums, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool check(vector<int>& nums, int k, int m) {
        int x = 0;
        int y = 1;
        for (int i: nums) {
            if (x + i > m) {
                ++y;
                x = 0;
            }
            x += i;
            if (x > m) return false;
        }

        return y <= k;
    }
};