class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> check1(26, 0), check2(26, 0);

        int l = 0;

        for (int i = 0; i < s1.size(); ++i) {
            check1[s1[i] - 'a']++;
            check2[s2[i] - 'a']++;
        }

        if (check1 == check2) return true;

        for (int r = s1.size(); r < s2.size(); ++r) {
            check2[s2[l] - 'a']--;
            check2[s2[r] - 'a']++;
            if (check1 == check2) return true;
            ++l;
        }

        return false;
    }
};
