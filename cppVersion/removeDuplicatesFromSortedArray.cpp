/*
    link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result;
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        for(auto i=nums.begin(); i!=nums.end();) {
            if(i!=nums.begin() && *i == *(i-1)) {
                nums.erase(i);
            }else{
                i++;
            }
        }
        return nums.size();
    }
};
