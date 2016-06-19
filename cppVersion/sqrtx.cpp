/*
    Link: https://leetcode.com/problems/sqrtx/
    Discuss: https://leetcode.com/discuss/24942/a-binary-search-solution
    Tips: Using m > x/m instead of m^2 > x to avoid overflow. Nice trick!
          Binary search: mid = left + (right - left)/2 !
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int left=1;
        int right = INT_MAX;
        while(true) {
            int mid = left + (right - left) / 2;
            if(mid > x / mid) right = mid - 1;
            else if((mid+1) > x / (mid+1)) return mid;
            else {
                left = mid + 1;
            }
        }
    }
};
