// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 1;
        int move = 0;
        int count = 0;
        if(n<=0) return false;
        while(n != 0){
            count += ((n & (1<<move))>>move);
            n -= (n & (1<<move));
            move++;
        }
        return count ==1? true:false;
    }
};
