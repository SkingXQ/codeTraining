/*
    link: https://leetcode.com/problems/powx-n/
    solution: https://leetcode.com/discuss/106555/c-simple-iterative
    tips:
        1. Once met the same style problem which over time limitation, I should think about the bits operation
        2. This problem is similar to the easy method to solve the operation of tweo pow 2, n
            if n = 5 , b00000101, 
               n = b 100 + b 1
               2^5 = 2^4 + 2 ^ 1
*/


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        long long int absn = n;
        if(n < 0) absn = -absn;
        double result = 1;
        while(absn > 0) {
            if(absn & 1 ) 
                result *= x;
            cout<<result<<endl;
            x *= x;
            absn >>= 1;
        }
        
        if(n < 0) {
            result = 1 / result;
        }
        return result;
    }
};
