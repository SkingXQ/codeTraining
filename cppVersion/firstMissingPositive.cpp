/*
    Link: https://leetcode.com/problems/first-missing-positive/
    Discuss: https://leetcode.com/discuss/24013/my-short-c-solution-o-1-space-and-o-n-time
    Tips: According to the question: "Your algorithm should run in O(n) time and uses constant space."
          It imply that You should exchange the nums in-place and add use few O(0) space;
          I try to use some space to store the missing one but it use O(n) space.
          The discussion give the wonderful solution;
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()) return 1;

        for(int i=0; i < nums.size(); i++) {
            while((nums[i]>0 && nums[i] <= nums.size()) && nums[i] != i+1) {
                int tmp = nums[i];
                if(nums[tmp-1] == tmp) break;
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            }
        }
        
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};
