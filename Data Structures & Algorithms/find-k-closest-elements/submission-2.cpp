class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;

        // Shrink window [l, r] until its size is k
        while (r - l + 1 > k) {
            if (abs(x - arr[l]) > abs(arr[r] - x)) {
                ++l;      // drop left: it's worse
            } else {
                --r;      // drop right
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};