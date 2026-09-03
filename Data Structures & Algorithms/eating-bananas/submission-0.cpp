class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;                         // không để 0
        int r = 0;
        for (int i : piles) {
            r = max(r, i);                 // upper bound
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(piles, h, m)) r = m;
            else l = m + 1;
        }
        return l;
    }

    bool check(const vector<int>& piles, int h, int k) {
        long long x = 0;                   // tránh overflow
        for (int i : piles) {
            // x += ceil((double)i / k);
            x += (i + k - 1) / k;          // cách integer chuẩn
        }
        return x <= h;
    }
};