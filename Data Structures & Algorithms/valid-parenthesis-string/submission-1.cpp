class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // minimum possible '(' open
        int maxOpen = 0; // maximum possible '(' open

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // '*'
                // '*' can be ')', '(' or empty:
                //   - for minOpen, treat as ')':   -1
                //   - for maxOpen, treat as '(':   +1
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0) return false;        // too many ')'
            if (minOpen < 0) minOpen = 0;         // clamp
        }
        return minOpen == 0;
    }
};
