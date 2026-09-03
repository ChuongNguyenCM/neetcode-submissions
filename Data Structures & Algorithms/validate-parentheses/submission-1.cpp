class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1 || s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        }
        stack<char> stack;
        stack.push(s[0]);

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.empty()) return false;
                char node = stack.top();
                stack.pop();

                if (node == '(') {
                    if (s[i] != ')') return false;
                } else if (node == '{') {
                    if (s[i] != '}') return false;
                } else {
                    if (s[i] != ']') return false;
                }
            }
        }
        if (!stack.empty()) return false;

        return true;

    }
};
