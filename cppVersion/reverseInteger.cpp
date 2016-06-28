/*
    Link: https://leetcode.com/problems/reverse-integer/
    Discuss: https://leetcode.com/discuss/80685/8-ms-simple-c-solution-which-checks-overflow
    Tips: I take a rest and copy the code from the discussion.
	  The method check the overflow with "if" sentence. and the interesting part is the 
          negative or  non-negative of integer with maintained by the divided by 10.
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};
