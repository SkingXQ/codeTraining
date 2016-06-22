/*
    Link: https://leetcode.com/problems/contains-duplicate-ii/
    Tips: space for time
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!nums.size()) return false;
        unordered_map<int, pair<int, int>> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) m[nums[i]] = make_pair(i, (i-m[nums[i]].first>m[nums[i]].second?m[nums[i]].second:i-m[nums[i]].first));
            else
                m.insert(make_pair(nums[i], make_pair(i, INT_MAX)));
        }
        for(auto i : m){
            if(i.second.second <= k) return true; 
        }
        return false;
    }
};
