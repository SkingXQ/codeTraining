#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s =nums.size()-1;
        return subset(nums, 0, s);
    }

    vector<vector<int>> subset(vector<int>& nums, int begin, int end) {
        vector<vector<int>> ret = {};
        ret.push_back(vector<int>{});
        if(begin > end) return ret;
        else {
            ret.clear();
            vector<vector<int>> t  = subset(nums, begin+1, end);
            for(auto& i: t) {
                ret.push_back(i);
                i.push_back(nums[begin]);
                ret.push_back(i);
            }
            return ret;
        }
    }
};

int main() {
    Solution t;
    vector<int> a = {1,2,3};
    vector<vector<int>> p = t.subsets(a);
    for(auto v : p) {
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
