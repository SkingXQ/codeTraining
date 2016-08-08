/*
    Link: https://leetcode.com/problems/top-k-frequent-elements/
    Solution: http://blog.csdn.net/NNNNNNNNNNNNY/article/details/51621761
              https://www.hrwhisper.me/leetcode-top-k-frequent-elements/
    Tips: becare the useage of multimap and priority_queue
*/

#include<vector>
#include<iostream>
#include<map>

using namespace std;

 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret = {};
        map<int, int> ref;
        for(int i=0; i<nums.size(); ++i) {
            if (ref.count(nums[i]) == 0) ref.insert(make_pair(nums[i], 1));
            else ref[nums[i]]++;
        }      
        multimap<int, int, greater<int>> mref;
        for(map<int, int>::iterator i=ref.begin(); i != ref.end(); i++){
            mref.insert(make_pair(i->second, i->first));
        }
        multimap<int, int>::iterator t = mref.begin();
        for(int i=0; i < k; i++) {
            ret.push_back(t->second);
            t++;
        }
        return ret;
    }
};

int main() {
    int s = 2;
    vector<int>  input = {1,1,1,2,2,3};
    Solution t;
    vector<int> r = t.topKFrequent(input, s);
    for(int i=0; i<r.size(); i++) {
         cout<<r[i]<<endl;
    }
    return 0;
}
