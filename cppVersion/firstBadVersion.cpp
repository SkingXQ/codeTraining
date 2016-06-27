/*
    Link: https://leetcode.com/problems/first-bad-version/
    Tips: binary search . nothing specail
*/

class Solution {
public:
int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(isBadVersion(mid) == true)
        {
             if(mid <= 1)
                break;
             if(isBadVersion(mid-1) == false)
                return mid;
             high = mid-1;
        }
        else
            low = mid +1;
    }
    return low;
  }
};
