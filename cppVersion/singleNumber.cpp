/*
 base on state machine
    link: https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto i = nums.begin(); i!=nums.end(); i++) {
            result = result ^ *i;
        }
        return result;
    }
};
