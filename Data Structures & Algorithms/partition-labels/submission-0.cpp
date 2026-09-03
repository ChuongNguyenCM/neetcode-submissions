class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        unordered_set<char> set;
        vector<int> ans;

        for (char c: s) map[c]++;

        int check = 0;
        int x = 0;

        for (char c: s) {
            x++;
            if (!set.count(c)){
                set.insert(c);
                check++;
            }
            map[c]--;
            if (map[c] == 0) check--;
            if (check == 0) {
                ans.push_back(x);
                x = 0;
                set.clear();
            }
        }

        return ans;
    }
};
