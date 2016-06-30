/*
    Link: https://leetcode.com/problems/wiggle-sort-ii/
    Discuss: https://leetcode.com/discuss/77115/o-n-time-o-1-space-solution-with-detail-explanations
    Tips:  It's very easy to figure out that we cross two parts of numbers. One is the half smaller,
           and another is the half bigger. So we don't need to sort the whole arrays. We just split the 
           arrays. With likely partion sort, We can do it in average time is O(n)(worst situation no under considered).
           nth_element completes the requirement.
           (reference: http://www.tuicool.com/articles/2uM3mqR)
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }    
        int n = nums.size();

        // Step 1: Find the median          
        vector<int>::iterator nth = next(nums.begin(), n / 2);
        nth_element(nums.begin(), nth, nums.end());
        int median = *nth;

        // Step 2: Tripartie partition within O(n)-time & O(1)-space.           
        auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };          
        int first = 0, mid = 0, last = n - 1;
        while (mid <= last) {
            if (nums[m(mid)] > median) {
                swap(nums[m(first)], nums[m(mid)]);
                ++first;
                ++mid;
            }
            else if (nums[m(mid)] < median) {
                swap(nums[m(mid)], nums[m(last)]);
                --last;
            }               
            else {
                ++mid;
            }
        }
    }    
};
