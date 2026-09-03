class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string s: operations) {
            if (s == "+") {
                int a = st.top(); st.pop();
                int b = st.top();
                st.push(a); st.push(a + b);
            } else if (s == "D") {
                int a = st.top();
                st.push(a * 2);
            } else if (s == "C") {
                st.pop();
            } else {
                st.push(stoi(s));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }

        return ans;
    }
};