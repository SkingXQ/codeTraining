/*
   Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(!nums1.size() || !nums2.size()) return result;
        unordered_map<int, int> mapNums1;
        unordered_map<int, int> mapNums2;
        for(auto i : nums1) {
            if(!mapNums1.count(i))
                mapNums1.insert({i, 1});
            else
                mapNums1[i] += 1;
        }
         for(auto i : nums2) {
            if(!mapNums2.count(i))
                mapNums2.insert({i, 1});
            else
                mapNums2[i] += 1;
        }       
        for(auto i : mapNums1){
            if(mapNums2.count(i.first)) 
                result.insert(result.end(), min(mapNums1[i.first], mapNums2[i.first]), i.first);
        }
        return result;
    }
};
