#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> mapNums;
        for(auto i : nums) {
            mapNums[i]++;
        }   
        return subsetsWithDup(mapNums);
    }
    vector<vector<int>> subsetsWithDup(unordered_map<int, int>& mapNums) {
        vector<vector<int>> ret = {{}};
        vector<vector<int>> tret = {};
        if(mapNums.size() == 0) return ret;
        int count = (mapNums.begin())->second;
        int nums = (mapNums.begin())->first;
        mapNums.erase(mapNums.begin());
        vector<vector<int>>  tmp = subsetsWithDup(mapNums);
        for(int i=0; i<count; i++) {
            vector<int> t(i+1, nums);
            tret.push_back(t);
        }
        for(auto t:tmp) 
           if(t.size()) ret.push_back(t);
        for(auto tr:tret)
           ret.push_back(tr);
        for(auto tr : tret) {
           for(auto t : tmp) {
               if(!t.size()) continue;
               vector<int> tt(tr.begin(), tr.end());
               tt.insert(tt.begin(), t.begin(), t.end());
               ret.push_back(tt);
           }
        }
              
        return ret;
    }
};

int main() {
    Solution t;
    vector<int> a = {1,2,3};
    vector<vector<int>> ret = t.subsetsWithDup(a);
    for(auto r : ret) {
        for(auto i : r) 
            cout<<i<<" ";
        cout<<endl;
    }
}
