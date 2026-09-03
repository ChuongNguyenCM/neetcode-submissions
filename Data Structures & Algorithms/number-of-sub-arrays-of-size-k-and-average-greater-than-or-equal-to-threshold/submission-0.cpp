class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int sum = 0;
        int l = 0;
        for (int i = 0; i < k - 1; ++i) sum += arr[i];

        for (int r = k - 1; r < arr.size(); ++r) {
            sum += arr[r];
            if ((float)sum / k >= threshold) ans++;

            sum -= arr[l];
            ++l;
        }

        return ans;
    }
};