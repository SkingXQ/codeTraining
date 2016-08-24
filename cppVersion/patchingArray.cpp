/* Link: https://leetcode.com/problems/patching-array/
 * Solution: http://www.bubuko.com/infodetail-1345277.html
 * Tips: I think It's more like DP instead of greedy.
         We know the nums is ordered.
         and we can use [1, 2, 4 and so on to get the whole ints.
         From very beginning , we can get all ints before nums[0].
         We assume that [0, total) we could get any numbers with  nums before index in nums or the num we add.
         So that when we can use get [0, total + nums[index]) which nums[index] never show up before.((total-nums[index]+nums[index], total + nums[index]] is)
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int total = 1;
        long long int index = 0;
        int res = 0;
        while(total <= n) {
            if(index < nums.size() && nums[index] <= total) {
                total += nums[index];
                index++;
            } else {
                total += total;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution t;
    vector<int> a= {1,2,31,33};
    cout<<t.minPatches(a, 2147483647)<<endl;

}
