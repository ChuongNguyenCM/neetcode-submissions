class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> check;
        int n = profits.size();

        for (int i = 0; i < n; i++) {
            check.push_back({capital[i], profits[i]});
        }

        sort(check.begin(), check.end());

        priority_queue<int> maxHeap;

        int i = 0;
        int j = 0;
        while (i < k) {
            if (j < n && w < check[j].first) break;
            
            while (j < n && w >= check[j].first) {
                maxHeap.push(check[j].second);
                ++j;
            }

            w += maxHeap.top(); maxHeap.pop();
            ++i;
        }

        return w;
    }
};