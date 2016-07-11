/*
    Link: https://leetcode.com/problems/sum-of-two-integers/
    Solution: https://www.hrwhisper.me/leetcode-sum-two-integers/
    Reference: how the int restore in the computer: https://zh.wikipedia.org/wiki/%E6%9C%89%E7%AC%A6%E8%99%9F%E6%95%B8%E8%99%95%E7%90%86
    Tips: I shall understand how the integers restore int the computer.
          I shall finish the ^ and & motion in the whole integers.
*/

class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        carry <<= 1;
        int result = a ^ b;
        while(carry) {
            int c = result & carry;
            result ^= carry;
            carry = c<<1;
        }
        return result;
    }
};
