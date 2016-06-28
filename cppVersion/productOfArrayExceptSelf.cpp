/*
    Link: https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 2) return {nums[1], nums[0]};
        vector<int> output(nums.begin(), nums.end());
        int t = 1;
        int c = 1;
        for(int i=0; i < nums.size(); i++) {
            c *= t;
            t = nums[i];
            nums[i] = c;
        }
        t = 1;
        c = 1;
        for(int i=nums.size()-1; i >= 0; i--) {
            c *= t;
            t = output[i];
            output[i] = c;
        }
        for(int i=0; i < nums.size(); i++) {
            output[i] *= nums[i];
        }
        return output;
    }
};
