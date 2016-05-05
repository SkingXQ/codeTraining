/*
    link: https://leetcode.com/problems/maximum-subarray/
    other solution: https://leetcode.com/discuss/71696/my-c-o-n-solution-lol
    tip:
          i should promote this method.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int sum=nums[0];
        int low_sum = sum>0? sum: 0;
        int high_sum = sum>0? 0: sum;
        int total_sum = nums[0];
        nums.insert(nums.begin(), 0);
        for(int i=2; i<nums.size(); i++) {
            if(low_sum > sum && low_sum != 0) sum=low_sum;
            if(nums[i] >= sum && low_sum <= 0) {
                sum = nums[i];
                high_sum = 0;
            }else if(nums[i] >= sum && low_sum > 0) {
                sum = nums[i] + low_sum;
                high_sum = 0;
            }else if(high_sum + nums[i] > 0) {
                sum += (high_sum + nums[i]);
                high_sum = 0;
            }else {
                high_sum += nums[i];
            }
            if(low_sum < nums[i] && low_sum < 0)
                low_sum = nums[i];
            else
                low_sum += nums[i];
            total_sum += nums[i];
        }
        return sum;
    }
};
