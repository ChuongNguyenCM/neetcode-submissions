class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x = digits[digits.size() - 1] + 1;
        int carry = x / 10; 
        digits[digits.size() - 1] = x % 10;
        for (int i = digits.size() - 2; i >= 0; i--) {
            if (carry == 0) break;
            x = digits[i] + carry;
            carry = x / 10;
            digits[i] = x % 10;
        }       

        if (carry == 1) digits.insert(digits.begin(), 1);

        return digits;
    }
};
