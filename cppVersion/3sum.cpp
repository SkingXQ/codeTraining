/*
    linK: https://leetcode.com/problems/3sum/
*/
/* tips
    1 be care for the repeating nums in first position, compare it to pre nums,
    2 when finding traget, remove the repeating part in the rest in case of duplicated vector.
    3 sorting is important
    */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int begin = 0;
        int end = nums.size()-1;
        int target = 0;
        for(int i = 0; i < nums.size()-2; i++){
            target = 0 - nums[i];
            begin = i + 1;
            end = nums.size() - 1;
            if(i !=0 && nums[i] == nums[i-1])//tips one
                continue;
            while(begin < end){
                if(nums[begin] + nums[end] < target)
                    begin++;
                else if(nums[begin] + nums[end] > target)
                    end--;
                else if(nums[begin] + nums[end] == target){
                    vector<int> temp = {nums[i], nums[begin], nums[end]};
                    result.push_back(temp);
                    while(nums[begin] == nums[begin + 1]) //tips two
                        begin++;
                    while(nums[end] == nums[end-1])
                        end--;
                        
                    begin++;
                    end--;
                }
            }
        }
        return result;
    }
};
