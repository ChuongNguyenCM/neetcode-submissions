class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long l = 0, r = 0;
        for (int w : weights) {
            r += w;
            l = max<long long>(l, w);   // capacity tối thiểu phải ≥ trọng lượng lớn nhất
        }

        while (l < r) {
            long long m = (r + l) / 2;
            if (check(weights, days, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool check(vector<int>& weights, int days, long long m) {
    int usedDays = 1;      // bắt đầu từ ngày 1
    long long cur = 0;
    for (int w : weights) {
        if (w > m) return false;          // món hàng lớn hơn capacity -> impossible
        if (cur + w > m) {                // sang ngày mới
            usedDays++;
            cur = 0;
        }
        cur += w;
    }
    return usedDays <= days;
}
};