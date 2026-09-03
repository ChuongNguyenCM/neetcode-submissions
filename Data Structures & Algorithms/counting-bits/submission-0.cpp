class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};

        vector<int> ans(n + 1, 0);
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (i == pow(2, k + 1) - 1){
                ans[i] = ans[i - pow(2, k)] + 1;
                k++;
            } else if (i >= pow(2, k)) {
                ans[i] = ans[i - pow(2, k)] + 1;
            }
        }

        return ans;
    }
};
