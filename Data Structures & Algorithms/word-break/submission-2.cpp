class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        vector<bool> check(s.size(), false);
        
        if (set.count(s.substr(0, 1))) check[0] = true;

        for (int i = 1; i < s.size(); i++) {
            if (set.count(s.substr(0, i + 1))) {
                check[i] = true;
                continue;
            }

            for (int j = 0; j < i; j++) {
                if (check[j] && set.count(s.substr(j + 1, i - j))) {
                    check[i] = true;
                    continue;
                }
            }
        }

        return check.back();
    }
};
