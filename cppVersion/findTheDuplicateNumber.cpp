/*
    Link: https://leetcode.com/problems/find-the-duplicate-number/
    Discuss: https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
    Tips: It is the same as find the entry point of a loop lists. The vector is the list node without val, just pointer.
          First while is used for entering the loop. Second while is used for find the entry point.
          It's easy understand if drawing a linked list/
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(!nums.size()) return -1;
        int slow = nums[0];
        int fast = nums[slow];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];// fast = nums[fast]; fast = nums[fast], two ahead;
        }
        
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
