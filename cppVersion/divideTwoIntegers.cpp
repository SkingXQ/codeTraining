/*
    link:https://leetcode.com/problems/divide-two-integers/
    solution: https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
    tip :
          there is a lot of skill must read again;
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if((divisor == 0) || (dividend == INT_MIN && divisor == -1 ))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0))? -1:1;
        long long ldividend = labs(dividend);
        long long ldivisor = labs(divisor);
        long long res = 0;
        while(ldividend >= ldivisor) {
            long long multi = 1;
            long long count = ldivisor;
            while(ldividend >= (count<<1)) {
                count <<= 1;
                multi <<= 1;
            }
            ldividend -= count;
            res += multi;
        }
        return sign>0? res: -res;
    }
};
