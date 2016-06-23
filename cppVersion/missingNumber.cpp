/*
    Link: https://leetcode.com/problems/missing-number/
    Tips: similar with first missing number
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(!nums.size()) return 1;
        int s = nums.size();
        for(int i=0; i<s; i++) {
            cout<<nums[i]<<endl;
            if(s == nums[i]) nums.push_back(s);
            else if(nums[i] != i && nums[nums[i]] != nums[i]){
                int t = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = t;
                i--;
            }
        }
        for(auto i=0; i<s+1; i++) {
            if(nums[i] != i)  return i;
        }
        return nums.back()+1;
    }
};
