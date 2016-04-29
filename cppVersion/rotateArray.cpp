/* https://leetcode.com/problems/rotate-array/
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        if(nums.size() < k ){
            k = k - nums.size();
        }
        divide(nums, 0, nums.size()-1-k);
        divide(nums, nums.size()-k, nums.size()-1);
        divide(nums, 0, nums.size()-1);
       
    }
    void divide(vector<int>& nums, int left, int right){
        if(left > right) return;
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
        divide(nums, left+1, right-1);
    }
};
