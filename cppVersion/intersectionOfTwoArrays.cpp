/*
    Link: https://leetcode.com/problems/intersection-of-two-arrays/
    Tips: key point is the initial of two sets:
          unordered_set<int> set1(nums1.begin(), nums1.end())
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(!nums1.size() || !nums2.size()) return result;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        for(auto s1 : set1){
            if(set2.count(s1))
                result.push_back(s1);
        }
        return result;
    }
};
