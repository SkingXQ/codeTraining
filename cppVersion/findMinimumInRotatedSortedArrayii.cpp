/*
    Link:https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
    Discuss : https://leetcode.com/discuss/19746/my-pretty-simple-code-to-solve-it 
    Tips: just comparing high with mid (or low and mid) will indicate the lowest one position
          high-- in this situation :
                      4 4 4 4 4       4
                                    3
                                  2
                                1
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1; 
        int mid = 0;
        while(low < high) {
            mid = low + (high - low) / 2;// in case low + high / 2 overflow
            cout<<nums[low] << " "<< nums[mid] << " " <<nums[high]<<endl;
            if(nums[high] > nums[mid]) {
                high = mid; // not mid - 1 for mid may be the lowest
            } else if(nums[high] < nums[mid]) {
                low = mid + 1;
            } else {
                high--;
            }
        }
        return nums[low];
    }
};

int main(){
    vector<int> a = {4,5,6,7,0,1,1,2};
    Solution b;
    cout<<(b.findMin(a))<<endl;
}
