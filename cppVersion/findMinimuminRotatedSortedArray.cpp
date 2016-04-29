/* 
    link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size() - 1;
        return divide(nums, 0, n);
    }
    
    int divide(vector<int>& nums, int left, int right){
        if(right - left == 1){
            if(nums[right]<nums[left])
                return nums[right];
            else
                return nums[left];
        }
        if(nums[(left+right)/2] > nums[right] && nums[(left+right)/2] > nums[left]){
            return divide(nums, (left+right)/2, right);}
        else if(nums[(left+right)/2] < nums[right] && nums[(left+right)/2] < nums[left]){
            return divide(nums, left, (left+right)/2);}
        else if(nums[(left+right)/2] < nums[right] && nums[(left+right)/2] >= nums[left]){
            return nums[left];}
    }
};
