class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int>& arr, int l, int r) {
        if (r - l + 1 <= 1) return;

        int pv = arr[r];
        int x = l;
        for (int i = l; i < r; i++) {
            if (arr[i] < pv) swap(arr[x++], arr[i]);
        }

        arr[r] = arr[x];
        arr[x] = pv;

        quicksort(arr, l, x - 1);
        quicksort(arr, x + 1, r);
    }
};