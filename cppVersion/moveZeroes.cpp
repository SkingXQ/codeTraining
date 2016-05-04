/*
    link:  https://leetcode.com/problems/move-zeroes/
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0)  return;
        int s = nums.size();
        for(auto i=nums.begin(); i!=nums.end(); ) { 
            if(*i == 0) {
                nums.erase(i);
            }else{
                i++;
            }   
        }   
        for(int i=nums.size(); i != s; i++) {
            nums.insert(nums.end(), 0); 
        }
    }   
};
