class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> set;
       for (int i: nums) {
            if (set.count(i)) {
                return true;
            }
            set.insert(i);
       } 
       return false;
    }
};