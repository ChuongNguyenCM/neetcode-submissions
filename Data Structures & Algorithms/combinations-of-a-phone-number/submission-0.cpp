class Solution {
public:
    unordered_map<char, vector<char>> map = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr = "";
        backtrack(curr, 0, digits);
        return ans;
    }

    void backtrack(string& curr, int x, string& digits) {
        if (x == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char c: map[digits[x]]) {
            curr.push_back(c);
            backtrack(curr, x + 1, digits);
            curr.pop_back();
        }
    }
};
