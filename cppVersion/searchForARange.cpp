/*
    link:   https://leetcode.com/problems/search-for-a-range/
*/
class Solution {
private:
    int binarySearchLow(vector<int>& nums, int target , int left, int right){
        if(left == right){
            if(nums[left] == target) return left;
            else return -1;
        }
        if(nums[(right+left)/2] >= target){
            return binarySearchLow(nums, target, left, (right+left)/2);
        }else{
            return binarySearchLow(nums, target, (right+left)/2 + 1, right);
        }
    }
    int binarySearchHigh(vector<int>& nums, int target , int left, int right){
        if(left == right){
            if(nums[left] == target) return left;
            else return -1;
        }
        if(nums[(right+left)/2+1] <= target){
            return binarySearchHigh(nums, target, (right+left)/2+1, right);
        }else{
            return binarySearchHigh(nums, target, left, (right+left)/2);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0] = binarySearchLow(nums, target, 0, nums.size()-1);
        result[1] = binarySearchHigh(nums, target, 0, nums.size()-1);

        return result;
    }
};
