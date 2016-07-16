/*
    Link: https://leetcode.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1; i >= 0; i--) {
            if(carry) {
                if(digits[i] == 9) {
                    digits[i] = 0;
                    carry = 1;
                }else{
                    carry = 0;
                    digits[i] += 1;
                }
            }else break;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
