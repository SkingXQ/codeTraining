/*
    link: https://leetcode.com/problems/contains-duplicate-iii/
    solution: https://leetcode.com/discuss/79033/c-20ms-solution-beating-91%25-others
    tip
       translate the distance between positions to distance bewtween number contained.
       reduce the time complexity.
       by the way the sort function useage
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2) return false;
        if(k==0) return false;
        vector<pair<long, int>> tmp;
        for(int i=0; i<nums.size(); i++) {
            tmp.push_back(make_pair((long)nums[i], i));
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size();) {
                if(abs(tmp[i].first-tmp[j].first) <= t) {
                    if(abs(tmp[i].second-tmp[j].second) <= k)
                        return true;
                    else
                        j++;
                }else{
                    break;
                }
            }
        }
        return false;
    }
    
    static bool cmp(pair<long, int> a, pair<long,int> b) {
        return a.first < b.first;
    }
};

