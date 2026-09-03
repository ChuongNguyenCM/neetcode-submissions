class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i: asteroids) {
            if (i > 0) st.push(i);
            else {
                if (st.empty() || st.top() < 0) {
                    st.push(i);
                    continue;
                }

                bool flag = false;
                while (!st.empty() && st.top() > 0) {
                    if (abs(i) < st.top()) break;
                    else if (abs(i) == st.top()) {
                        st.pop();
                        break;
                    } else {
                        st.pop(); flag = true;
                    }
                }
                if (flag && (st.empty() || st.top() < 0)) st.push(i);
            }
        }

        if (st.empty()) return {};

        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i] = st.top(); st.pop();
            --i;
        }

        return ans;
    }
};