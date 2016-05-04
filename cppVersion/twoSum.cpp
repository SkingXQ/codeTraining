/*
    link: https://leetcode.com/problems/two-sum/
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(nums[j]==target-nums[i])
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }  
        }
        return res;
    }
};
