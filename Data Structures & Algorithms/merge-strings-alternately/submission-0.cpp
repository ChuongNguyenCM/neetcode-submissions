class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int x1 = 0, x2 = 0;

        while (x1 < word1.size() && x2 < word2.size()) {
            s.push_back(word1[x1]);
            s.push_back(word2[x2]);
            ++x1; ++x2;
        }

        while (x1 < word1.size()) {
            s.push_back(word1[x1]);
            ++x1;
        }

        while (x2 < word2.size()) {
            s.push_back(word2[x2]);
            ++x2;
        }

        return s;
    }
};