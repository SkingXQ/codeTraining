/*
    Link: https://leetcode.com/problems/3sum-closest/
    Tips: pleas be careful that :
               if(nums[begin]+nums[end] < tmp &&  
                   abs(target-nums[begin]-nums[end]-nums[i]) <= abs(result))
          and 
               if(nums[begin]+nums[end] > tmp &&  
                   abs(target-nums[begin]-nums[end]-nums[i]) < abs(result))

          It will cause the chosen number set of the sorted vector stay in small side 
          and if 17 and 19 is avalueable for answer (18 is target)it will be 17.
*/
#include<iostream>
#include<vector>
#include<set>
#include<limits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int begin = 0;
        int end = nums.size() - 1;
        int tmp = 0;
        int result = 2147483646;
        int r = target;
        for(int i = 0; i < nums.size() - 2; i++) {
            tmp = target - nums[i];
            begin = i + 1;
            end = nums.size() - 1;
            cout<<"begin "<<nums[i]<<endl;
            while(begin < end) {
                cout<<"tmp "<<tmp<<" minu "<<(target-nums[begin]-nums[end]-nums[i])<<" result "<<result<<endl;
                if(nums[begin]+nums[end] == tmp)
                    return target;
                if(nums[begin]+nums[end] < tmp && 
                   abs(target-nums[begin]-nums[end]-nums[i]) <= abs(result)) {     
                    result = nums[begin]+nums[end]+nums[i]-target ;
                    begin++;   
                }else if (nums[begin]+nums[end] < tmp &&  
                          abs(target-nums[begin]-nums[end]-nums[i]) > abs(result)) begin++;
                if(nums[begin]+nums[end] > tmp &&
                   abs(target-nums[begin]-nums[end]-nums[i]) < abs(result)) {
                    result = nums[begin]+nums[end]+nums[i]-target;
                    end--;
                }else if(nums[begin]+nums[end] > tmp &&
                         abs(target-nums[begin]-nums[end]-nums[i]) >= abs(result)) end--;
            }
        }
        return target+result;
    }
};


int main() {
    Solution test;
    vector<int> a={-10,0,-2,3,-8,1,-10,8,-8,6,-7,0,-7,2,2,-5,-8,1,-4,6};
    cout<<test.threeSumClosest(a,18)<<endl;
}
