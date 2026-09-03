class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stack;
        stack.push(0);

        for (int i = 1; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }

            stack.push(i);
        }

        return ans;
    }
};
