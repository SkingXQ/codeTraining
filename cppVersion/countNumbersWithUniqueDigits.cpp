/*
    link: https://leetcode.com/problems/count-numbers-with-unique-digits/
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) return countNumbersWithUniqueDigits(10);
        if(n == 0) return 1;
        int result = 10;
        for(int factor=0, accum=9; factor < n-1; factor++)
        {
            accum *= (9 - factor);
            result += accum;
        }
        
        return result;
    }
};
