/*
    link : https://leetcode.com/problems/4sum/
    solution: https://leetcode.com/discuss/99761/leetbook-4sum%E8%BD%AC%E6%8D%A2%E6%88%903sum%E9%97%AE%E9%A2%98%EF%BC%88%E9%99%84%E8%A7%A3%E9%87%8A%EF%BC%8C%E5%9B%BE%E7%A4%BA%EF%BC%8C%E4%BB%A3%E7%A0%81%EF%BC%89
    tips:
         be careful the situation : the duplicate numbers. while(++j < nums.size()-1 && nums[j] == nums[j-1])
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() < 4)  return result;
        for(int i=0; i != nums.size()-3; i++) {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int t = target - nums[i];
            vector<vector<int>> r = threeSum(nums, t, i);
            for(auto j=r.begin(); j != r.end(); j++) {
                (*j).push_back(nums[i]);
                sort((*j).begin(), (*j).end());
                result.push_back(*j);
            }
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int target, int pos) {
        vector<vector<int>> result;
        for(int i = pos+1; i < nums.size()-2; i++) {
            if(i != pos+1 && nums[i] == nums[i-1]) continue;
            int t = target - nums[i];
            for(int j=i+1, k=nums.size()-1; j<k; ) {
                //if(j != i+1 && nums[j] == nums[j-1]) continue;
                ///if(k != nums.size()-1 && nums[k] == nums[k+1]) continue;
                if(nums[j] + nums[k] == t) {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while(++j <nums.size()-1 && nums[j] == nums[j-1]);
                    while(--k > 0 && nums[k] == nums[k+1]);
                }else if(nums[j] + nums[k] < t)
                    j++;
                else if(nums[j] + nums[k] > t)
                    k--;
            }
        }
        return result;
    }
};
