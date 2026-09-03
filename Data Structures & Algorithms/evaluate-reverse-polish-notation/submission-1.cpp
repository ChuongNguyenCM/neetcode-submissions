class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> stack;
        for (string c: tokens) {
            if (c != "+" & c != "-" & c != "*" & c != "/") stack.push(stoi(c));
            else {
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                int z;
                if (c == "+") z = x + y;
                else if (c == "-") z = y - x;
                else if (c == "*") z = x * y;
                else if (c == "/") z = y / x;
                stack.push(z);
            }
        }

        return stack.top();
    }
};
